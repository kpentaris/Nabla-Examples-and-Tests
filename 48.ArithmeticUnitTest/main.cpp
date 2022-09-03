#define _IRR_STATIC_LIB_
#include <nabla.h>

#include "../common/CommonAPI.h"

using namespace nbl;
using namespace core;
using namespace video;
using namespace asset;

template<typename T>
struct and_op
{
	using type_t = T;
	static inline constexpr T IdentityElement = std::bit_cast<T,uint32_t>(~0ull);

	inline T operator()(T left, T right) { return left & right; }
	static inline constexpr bool runOPonFirst = false;
	static inline constexpr const char* name = "and";
};
template<typename T>
struct xor_op
{
	using type_t = T;
	static inline const T IdentityElement = std::bit_cast<T,uint32_t>(0ull);

	inline T operator()(T left, T right) { return left ^ right; }
	static inline constexpr bool runOPonFirst = false;
	static inline constexpr const char* name = "xor";
};
template<typename T>
struct or_op
{
	using type_t = T;
	static inline const T IdentityElement = std::bit_cast<T,uint32_t>(0ull);

	inline T operator()(T left, T right) { return left | right; }
	static inline constexpr bool runOPonFirst = false;
	static inline constexpr const char* name = "or";
};
template<typename T>
struct add_op
{
	using type_t = T;
	static inline constexpr T IdentityElement = T(0);

	inline T operator()(T left, T right) { return left + right; }
	static inline constexpr bool runOPonFirst = false;
	static inline constexpr const char* name = "add";
};
template<typename T>
struct mul_op
{
	using type_t = T;
	static inline constexpr T IdentityElement = T(1);

	inline T operator()(T left, T right) { return left * right; }
	static inline constexpr bool runOPonFirst = false;
	static inline constexpr const char* name = "mul";
};
template<typename T>
struct min_op
{
	using type_t = T;
	static inline constexpr T IdentityElement = std::numeric_limits<T>::max();

	inline T operator()(T left, T right) { return std::min<T>(left, right); }
	static inline constexpr bool runOPonFirst = false;
	static inline constexpr const char* name = "min";
};
template<typename T>
struct max_op
{
	using type_t = T;
	static inline constexpr T IdentityElement = std::numeric_limits<T>::lowest();

	inline T operator()(T left, T right) { return std::max<T>(left, right); }
	static inline constexpr bool runOPonFirst = false;
	static inline constexpr const char* name = "max";
};
template<typename T>
struct ballot : add_op<T> {};


//subgroup method emulations on the CPU, to verify the results of the GPU methods
template<class CRTP, typename T>
struct emulatedSubgroupCommon
{
	using type_t = T;

	inline void operator()(type_t* outputData, const type_t* workgroupData, uint32_t workgroupSize, uint32_t subgroupSize)
	{
		for (uint32_t pseudoSubgroupID=0u; pseudoSubgroupID<workgroupSize; pseudoSubgroupID+=subgroupSize)
		{
			type_t* outSubgroupData = outputData+pseudoSubgroupID;
			const type_t* subgroupData = workgroupData+pseudoSubgroupID;
			CRTP::impl(outSubgroupData,subgroupData,core::min<uint32_t>(subgroupSize,workgroupSize-pseudoSubgroupID));
		}
	}
};
template<class OP>
struct emulatedSubgroupReduction : emulatedSubgroupCommon<emulatedSubgroupReduction<OP>,typename OP::type_t>
{
	using type_t = typename OP::type_t;

	static inline void impl(type_t* outSubgroupData, const type_t* subgroupData, const uint32_t clampedSubgroupSize)
	{
		type_t red = subgroupData[0];
		for (auto i=1u; i<clampedSubgroupSize; i++)
			red = OP()(red,subgroupData[i]);
		std::fill(outSubgroupData,outSubgroupData+clampedSubgroupSize,red);
	}
	static inline constexpr const char* name = "subgroup reduction";
};
template<class OP>
struct emulatedSubgroupScanExclusive : emulatedSubgroupCommon<emulatedSubgroupScanExclusive<OP>,typename OP::type_t>
{
	using type_t = typename OP::type_t;

	static inline void impl(type_t* outSubgroupData, const type_t* subgroupData, const uint32_t clampedSubgroupSize)
	{
		outSubgroupData[0u] = OP::IdentityElement;
		for (auto i=1u; i<clampedSubgroupSize; i++)
			outSubgroupData[i] = OP()(outSubgroupData[i-1u],subgroupData[i-1u]);
	}
	static inline constexpr const char* name = "subgroup exclusive scan";
};
template<class OP>
struct emulatedSubgroupScanInclusive : emulatedSubgroupCommon<emulatedSubgroupScanInclusive<OP>,typename OP::type_t>
{
	using type_t = typename OP::type_t;

	static inline void impl(type_t* outSubgroupData, const type_t* subgroupData, const uint32_t clampedSubgroupSize)
	{
		outSubgroupData[0u] = subgroupData[0u];
		for (auto i=1u; i<clampedSubgroupSize; i++)
			outSubgroupData[i] = OP()(outSubgroupData[i-1u],subgroupData[i]);
	}
	static inline constexpr const char* name = "subgroup inclusive scan";
};

//workgroup methods
template<class OP>
struct emulatedWorkgroupReduction
{
	using type_t = typename OP::type_t;

	inline void operator()(type_t* outputData, const type_t* workgroupData, uint32_t workgroupSize, uint32_t subgroupSize)
	{
		type_t red = OP::runOPonFirst ? OP()(0, workgroupData[0]) : workgroupData[0];
		for (auto i=1u; i<workgroupSize; i++)
			red = OP()(red,workgroupData[i]);
		std::fill(outputData,outputData+workgroupSize,red);
	}
	static inline constexpr const char* name = "workgroup reduction";
};
template<class OP>
struct emulatedWorkgroupScanExclusive
{
	using type_t = typename OP::type_t;

	inline void operator()(type_t* outputData, const type_t* workgroupData, uint32_t workgroupSize, uint32_t subgroupSize)
	{
		outputData[0u] = OP::IdentityElement;
		for (auto i=1u; i<workgroupSize; i++)
			outputData[i] = OP()(outputData[i-1u],workgroupData[i-1u]);
	}
	static inline constexpr const char* name = "workgroup exclusive scan";
};
template<class OP>
struct emulatedWorkgroupScanInclusive
{
	using type_t = typename OP::type_t;

	inline void operator()(type_t* outputData, const type_t* workgroupData, uint32_t workgroupSize, uint32_t subgroupSize)
	{
		outputData[0u] = workgroupData[0u];
		for (auto i=1u; i<workgroupSize; i++)
			outputData[i] = OP()(outputData[i-1u],workgroupData[i]);
	}
	static inline constexpr const char* name = "workgroup inclusive scan";
};


#include "common.glsl"
constexpr uint32_t kBufferSize = (1u+BUFFER_DWORD_COUNT)*sizeof(uint32_t);

//returns true if result matches
template<template<class> class Arithmetic, template<class> class OP>
bool validateResults(ILogicalDevice* device, IUtilities* utilities, IGPUQueue* transferDownQueue, const uint32_t* inputData, const uint32_t workgroupSize, const uint32_t workgroupCount, video::IGPUBuffer* bufferToRead, asset::ICPUBuffer* resultsBuffer, system::ILogger* logger)
{
	bool success = true;

	SBufferRange<IGPUBuffer> bufferRange = {0u, kBufferSize, core::smart_refctd_ptr<IGPUBuffer>(bufferToRead)};
	utilities->downloadBufferRangeViaStagingBuffer(transferDownQueue, bufferRange, resultsBuffer->getPointer());

	auto dataFromBuffer = reinterpret_cast<uint32_t*>(resultsBuffer->getPointer());
	const uint32_t subgroupSize = (*dataFromBuffer++);

	// TODO: parallel for
	// now check if the data obtained has valid values
	uint32_t* tmp = new uint32_t[workgroupSize];
	uint32_t* ballotInput = new uint32_t[workgroupSize];
	for (uint32_t workgroupID=0u; success&&workgroupID<workgroupCount; workgroupID++)
	{
		const auto workgroupOffset = workgroupID*workgroupSize;
		if constexpr (std::is_same_v<OP<uint32_t>,ballot<uint32_t>>)
		{
			for (auto i=0u; i<workgroupSize; i++)
				ballotInput[i] = inputData[i+workgroupOffset]&0x1u;
			Arithmetic<OP<uint32_t>>()(tmp,ballotInput,workgroupSize,subgroupSize);
		}
		else
			Arithmetic<OP<uint32_t>>()(tmp,inputData+workgroupOffset,workgroupSize,subgroupSize);
		for (uint32_t localInvocationIndex=0u; localInvocationIndex<workgroupSize; localInvocationIndex++)
		if (tmp[localInvocationIndex]!=dataFromBuffer[workgroupOffset+localInvocationIndex])
		{
			logger->log(
				"Failed test #%d  (%s)  (%s) Expected %s got %s",system::ILogger::ELL_ERROR,
				workgroupSize,Arithmetic<OP<uint32_t>>::name,OP<uint32_t>::name,
				std::to_string(tmp[localInvocationIndex]),std::to_string(dataFromBuffer[workgroupOffset+localInvocationIndex])
			);
			success = false;
			break;
		}
	}
	delete[] ballotInput;
	delete[] tmp;

	return success;
}

constexpr const auto outputBufferCount = 8u;

template<template<class> class Arithmetic>
bool runTest(
	ILogicalDevice* device, IUtilities* utilities, IGPUQueue* transferDownQueue, IGPUQueue* queue, IGPUFence* reusableFence, IGPUCommandBuffer* cmdbuf, IGPUComputePipeline* pipeline, const IGPUDescriptorSet* ds,
	const uint32_t* inputData, const uint32_t workgroupSize, core::smart_refctd_ptr<IGPUBuffer>* const buffers, system::ILogger* logger, bool is_workgroup_test = false)
{
	// TODO: overlap dispatches with memory readbacks (requires multiple copies of `buffers`)

	cmdbuf->begin(IGPUCommandBuffer::EU_NONE);
	cmdbuf->bindComputePipeline(pipeline);
	cmdbuf->bindDescriptorSets(asset::EPBP_COMPUTE,pipeline->getLayout(),0u,1u,&ds);
	const uint32_t workgroupCount = BUFFER_DWORD_COUNT/workgroupSize;
	cmdbuf->dispatch(workgroupCount,1,1);
	IGPUCommandBuffer::SBufferMemoryBarrier memoryBarrier[outputBufferCount];
	for (auto i=0u; i<outputBufferCount; i++)
	{
		memoryBarrier[i].barrier.srcAccessMask = EAF_SHADER_WRITE_BIT;
		memoryBarrier[i].barrier.dstAccessMask = static_cast<asset::E_ACCESS_FLAGS>(EAF_SHADER_WRITE_BIT|EAF_HOST_READ_BIT);
		memoryBarrier[i].srcQueueFamilyIndex = cmdbuf->getQueueFamilyIndex();
		memoryBarrier[i].dstQueueFamilyIndex = cmdbuf->getQueueFamilyIndex();
		memoryBarrier[i].buffer = buffers[i];
		memoryBarrier[i].offset = 0u;
		memoryBarrier[i].size = kBufferSize;
	}
	cmdbuf->pipelineBarrier(
		asset::EPSF_COMPUTE_SHADER_BIT,static_cast<asset::E_PIPELINE_STAGE_FLAGS>(asset::EPSF_COMPUTE_SHADER_BIT|asset::EPSF_HOST_BIT),asset::EDF_NONE,
		0u,nullptr,outputBufferCount,memoryBarrier,0u,nullptr
	);
	cmdbuf->end();

	IGPUQueue::SSubmitInfo submit = {};
	submit.commandBufferCount = 1u;
	submit.commandBuffers = &cmdbuf;
	queue->submit(1u,&submit,reusableFence);
	device->blockForFences(1u,&reusableFence);
	device->resetFences(1u,&reusableFence);
	
	auto resultsBuffer = core::make_smart_refctd_ptr<ICPUBuffer>(kBufferSize);
	//check results 
	bool passed = validateResults<Arithmetic,and_op>(device, utilities, transferDownQueue, inputData, workgroupSize, workgroupCount, buffers[0].get(), resultsBuffer.get(),logger);
	passed = validateResults<Arithmetic,xor_op>(device, utilities, transferDownQueue, inputData, workgroupSize, workgroupCount, buffers[1].get(), resultsBuffer.get(),logger)&&passed;
	passed = validateResults<Arithmetic,or_op>(device, utilities, transferDownQueue, inputData, workgroupSize, workgroupCount, buffers[2].get(), resultsBuffer.get(),logger)&&passed;
	passed = validateResults<Arithmetic,add_op>(device, utilities, transferDownQueue, inputData, workgroupSize, workgroupCount, buffers[3].get(), resultsBuffer.get(),logger)&&passed;
	passed = validateResults<Arithmetic,mul_op>(device, utilities, transferDownQueue, inputData, workgroupSize, workgroupCount, buffers[4].get(), resultsBuffer.get(),logger)&&passed;
	passed = validateResults<Arithmetic,min_op>(device, utilities, transferDownQueue, inputData, workgroupSize, workgroupCount, buffers[5].get(), resultsBuffer.get(),logger)&&passed;
	passed = validateResults<Arithmetic,max_op>(device, utilities, transferDownQueue, inputData, workgroupSize, workgroupCount, buffers[6].get(), resultsBuffer.get(),logger)&&passed;
	if(is_workgroup_test)
	{
		passed = validateResults<Arithmetic,ballot>(device, utilities, transferDownQueue, inputData, workgroupSize, workgroupCount, buffers[7].get(), resultsBuffer.get(), logger)&&passed;
	}

	return passed;
}

class ArythmeticUnitTestApp : public NonGraphicalApplicationBase
{

public:
	void setSystem(nbl::core::smart_refctd_ptr<nbl::system::ISystem>&& s) override
	{
		system = std::move(s);
	}

	NON_GRAPHICAL_APP_CONSTRUCTOR(ArythmeticUnitTestApp)
	void onAppInitialized_impl() override
	{
		CommonAPI::InitOutput initOutput;
		CommonAPI::InitWithNoExt(initOutput, video::EAT_VULKAN, "Subgroup Arithmetic Test");
		gl = std::move(initOutput.apiConnection);
		gpuPhysicalDevice = std::move(initOutput.physicalDevice);
		logicalDevice = std::move(initOutput.logicalDevice);
		queues = std::move(initOutput.queues);
		renderpass = std::move(initOutput.renderpass);
		commandPools = std::move(initOutput.commandPools);
		assetManager = std::move(initOutput.assetManager);
		logger = std::move(initOutput.logger);
		inputSystem = std::move(initOutput.inputSystem);
		system = std::move(initOutput.system);
		cpu2gpuParams = std::move(initOutput.cpu2gpuParams);
		utilities = std::move(initOutput.utilities);
		
		auto transferDownQueue = queues[CommonAPI::InitOutput::EQT_TRANSFER_DOWN];

		nbl::video::IGPUObjectFromAssetConverter cpu2gpu;

		inputData = new uint32_t[BUFFER_DWORD_COUNT];
		{
			std::mt19937 randGenerator(std::time(0));
			for (uint32_t i = 0u; i < BUFFER_DWORD_COUNT; i++)
				inputData[i] = randGenerator();
		}

		IGPUBuffer::SCreationParams inputDataBufferCreationParams = {};
		inputDataBufferCreationParams.size = kBufferSize;
		inputDataBufferCreationParams.usage = core::bitflag<IGPUBuffer::E_USAGE_FLAGS>(IGPUBuffer::EUF_STORAGE_BUFFER_BIT) | IGPUBuffer::EUF_TRANSFER_DST_BIT;
		auto gpuinputDataBuffer = utilities->createFilledDeviceLocalBufferOnDedMem(queues[decltype(initOutput)::EQT_TRANSFER_UP], std::move(inputDataBufferCreationParams), inputData);

		//create 8 buffers.
		constexpr const auto totalBufferCount = outputBufferCount + 1u;

		core::smart_refctd_ptr<IGPUBuffer> buffers[outputBufferCount];
		for (auto i = 0; i < outputBufferCount; i++)
		{
			IGPUBuffer::SCreationParams params;
			params.size = kBufferSize;
			params.queueFamilyIndexCount = 0;
			params.queueFamilyIndices = nullptr;
			params.sharingMode = ESM_EXCLUSIVE;
			params.usage = core::bitflag(IGPUBuffer::EUF_STORAGE_BUFFER_BIT)|IGPUBuffer::EUF_TRANSFER_SRC_BIT;
			
			buffers[i] = logicalDevice->createBuffer(params);
			auto mreq = buffers[i]->getMemoryReqs();
			mreq.memoryTypeBits &= logicalDevice->getPhysicalDevice()->getDeviceLocalMemoryTypeBits();

			assert(mreq.memoryTypeBits);
			auto bufferMem = logicalDevice->allocate(mreq, buffers[i].get());
			assert(bufferMem.isValid());
		}

		IGPUDescriptorSetLayout::SBinding binding[totalBufferCount];
		for (uint32_t i = 0u; i < totalBufferCount; i++)
			binding[i] = { i,EDT_STORAGE_BUFFER,1u,IShader::ESS_COMPUTE,nullptr };
		auto gpuDSLayout = logicalDevice->createDescriptorSetLayout(binding, binding + totalBufferCount);

		constexpr uint32_t pushconstantSize = 8u * totalBufferCount;
		SPushConstantRange pcRange[1] = { IShader::ESS_COMPUTE,0u,pushconstantSize };
		auto pipelineLayout = logicalDevice->createPipelineLayout(pcRange, pcRange + 1u, core::smart_refctd_ptr(gpuDSLayout));

		auto descPool = logicalDevice->createDescriptorPoolForDSLayouts(IDescriptorPool::ECF_NONE, &gpuDSLayout.get(), &gpuDSLayout.get() + 1u);
		auto descriptorSet = logicalDevice->createDescriptorSet(descPool.get(), core::smart_refctd_ptr(gpuDSLayout));
		{
			IGPUDescriptorSet::SDescriptorInfo infos[totalBufferCount];
			infos[0].desc = gpuinputDataBuffer;
			infos[0].buffer = { 0u,kBufferSize };
			for (uint32_t i = 1u; i <= outputBufferCount; i++)
			{
				infos[i].desc = buffers[i - 1];
				infos[i].buffer = { 0u,kBufferSize };

			}
			IGPUDescriptorSet::SWriteDescriptorSet writes[totalBufferCount];
			for (uint32_t i = 0u; i < totalBufferCount; i++)
				writes[i] = { descriptorSet.get(),i,0u,1u,EDT_STORAGE_BUFFER,infos + i };
			logicalDevice->updateDescriptorSets(totalBufferCount, writes, 0u, nullptr);
		}

		auto getShaderGLSL = [&](const char* filePath) -> auto
		{
			IAssetLoader::SAssetLoadParams lparams;
			lparams.workingDirectory = std::filesystem::current_path();
			auto bundle = assetManager->getAsset(filePath, lparams);
			assert(!bundle.getContents().empty() && bundle.getAssetType() == IAsset::ET_SPECIALIZED_SHADER);
			return core::smart_refctd_ptr_static_cast<ICPUSpecializedShader>(*bundle.getContents().begin());
		};
		core::smart_refctd_ptr<ICPUSpecializedShader> shaderGLSL[] =
		{
			getShaderGLSL("../testSubgroupReduce.comp"),
			getShaderGLSL("../testSubgroupExclusive.comp"),
			getShaderGLSL("../testSubgroupInclusive.comp"),
			getShaderGLSL("../testWorkgroupReduce.comp"),
			getShaderGLSL("../testWorkgroupExclusive.comp"),
			getShaderGLSL("../testWorkgroupInclusive.comp")
		};
		constexpr auto kTestTypeCount = sizeof(shaderGLSL) / sizeof(const void*);

		auto getGPUShader = [&](const ICPUSpecializedShader* shader, uint32_t wg_count) -> auto
		{
			auto overridenUnspecialized = IGLSLCompiler::createOverridenCopy(shader->getUnspecialized(), "#define _NBL_GLSL_WORKGROUP_SIZE_ %d\n", wg_count);
			ISpecializedShader::SInfo specInfo = shader->getSpecializationInfo();
			auto cs = core::make_smart_refctd_ptr<ICPUSpecializedShader>(std::move(overridenUnspecialized), std::move(specInfo));
			return cpu2gpu.getGPUObjectsFromAssets(&cs, &cs + 1, cpu2gpuParams)->front();
			// no need to wait on fences because its only a shader create, does not result in the filling of image or buffers
		};

		auto logTestOutcome = [this](bool passed, uint32_t workgroupSize)
		{
			if (passed)
				logger->log("Passed test #%u", system::ILogger::ELL_INFO, workgroupSize);
			else
			{
				totalFailCount++;
				logger->log("Failed test #%u", system::ILogger::ELL_ERROR, workgroupSize);
			}
		};

		//max workgroup size is hardcoded to 1024
		const auto ds = descriptorSet.get();
		auto computeQueue = initOutput.queues[CommonAPI::InitOutput::EQT_COMPUTE];
		auto fence = logicalDevice->createFence(IGPUFence::ECF_UNSIGNALED);
		auto cmdPool = commandPools[CommonAPI::InitOutput::EQT_COMPUTE];
		core::smart_refctd_ptr<IGPUCommandBuffer> cmdbuf;
		logicalDevice->createCommandBuffers(cmdPool.get(), IGPUCommandBuffer::EL_PRIMARY, 1u, &cmdbuf);
		computeQueue->startCapture();
		for (uint32_t workgroupSize=45u; workgroupSize<=1024u; workgroupSize++)
		{
			core::smart_refctd_ptr<IGPUComputePipeline> pipelines[kTestTypeCount];
			for (uint32_t i = 0u; i < kTestTypeCount; i++)
				pipelines[i] = logicalDevice->createComputePipeline(nullptr, core::smart_refctd_ptr(pipelineLayout), std::move(getGPUShader(shaderGLSL[i].get(), workgroupSize)));

			bool passed = true;

			const video::IGPUDescriptorSet* ds = descriptorSet.get();
			passed = runTest<emulatedSubgroupReduction>(logicalDevice.get(), utilities.get(), transferDownQueue, computeQueue, fence.get(), cmdbuf.get(), pipelines[0u].get(), descriptorSet.get(), inputData, workgroupSize, buffers, logger.get()) && passed;
			logTestOutcome(passed, workgroupSize);
			passed = runTest<emulatedSubgroupScanExclusive>(logicalDevice.get(), utilities.get(), transferDownQueue, computeQueue, fence.get(), cmdbuf.get(), pipelines[1u].get(), descriptorSet.get(), inputData, workgroupSize, buffers, logger.get()) && passed;
			logTestOutcome(passed, workgroupSize);
			passed = runTest<emulatedSubgroupScanInclusive>(logicalDevice.get(), utilities.get(), transferDownQueue, computeQueue, fence.get(), cmdbuf.get(), pipelines[2u].get(), descriptorSet.get(), inputData, workgroupSize, buffers, logger.get()) && passed;
			logTestOutcome(passed, workgroupSize);
			passed = runTest<emulatedWorkgroupReduction>(logicalDevice.get(), utilities.get(), transferDownQueue, computeQueue, fence.get(), cmdbuf.get(), pipelines[3u].get(), descriptorSet.get(), inputData, workgroupSize, buffers, logger.get(), true) && passed;
			logTestOutcome(passed, workgroupSize);
			passed = runTest<emulatedWorkgroupScanExclusive>(logicalDevice.get(), utilities.get(), transferDownQueue, computeQueue, fence.get(), cmdbuf.get(), pipelines[4u].get(), descriptorSet.get(), inputData, workgroupSize, buffers, logger.get(), true) && passed;
			logTestOutcome(passed, workgroupSize);
			passed = runTest<emulatedWorkgroupScanInclusive>(logicalDevice.get(), utilities.get(), transferDownQueue, computeQueue, fence.get(), cmdbuf.get(), pipelines[5u].get(), descriptorSet.get(), inputData, workgroupSize, buffers, logger.get(), true) && passed;
			logTestOutcome(passed, workgroupSize);
		}
		computeQueue->endCapture();
	}

	void onAppTerminated_impl() override
	{
		logger->log("==========Result==========", system::ILogger::ELL_INFO);
		logger->log("Fail Count: %u", system::ILogger::ELL_INFO, totalFailCount);
		delete[] inputData;
	}

	void workLoopBody() override
	{
		//! the unit test is carried out on init
	}

	bool keepRunning() override
	{
		return false;
	}

	private:

		nbl::core::smart_refctd_ptr<nbl::video::IAPIConnection> gl;
		nbl::core::smart_refctd_ptr<nbl::video::IUtilities> utilities;
		nbl::core::smart_refctd_ptr<nbl::video::ILogicalDevice> logicalDevice;
		nbl::video::IPhysicalDevice* gpuPhysicalDevice;
		std::array<video::IGPUQueue*, CommonAPI::InitOutput::MaxQueuesCount> queues;
		nbl::core::smart_refctd_ptr<nbl::video::IGPURenderpass> renderpass;
		std::array<std::array<nbl::core::smart_refctd_ptr<nbl::video::IGPUCommandPool>, CommonAPI::InitOutput::MaxFramesInFlight>, CommonAPI::InitOutput::MaxQueuesCount> commandPools;
		nbl::core::smart_refctd_ptr<nbl::system::ISystem> system;
		nbl::core::smart_refctd_ptr<nbl::asset::IAssetManager> assetManager;
		nbl::video::IGPUObjectFromAssetConverter::SParams cpu2gpuParams;
		nbl::core::smart_refctd_ptr<nbl::system::ILogger> logger;
		nbl::core::smart_refctd_ptr<CommonAPI::InputSystem> inputSystem;

		uint32_t* inputData = nullptr;
		uint32_t totalFailCount = 0;
};

NBL_COMMON_API_MAIN(ArythmeticUnitTestApp)
