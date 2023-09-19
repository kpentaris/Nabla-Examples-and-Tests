// REVIEW: Not sure how the register types are chosen
// u -> For buffers that will be accessed randomly by threads i.e. thread 3 might access index 16
// b -> For uniform buffers
// t -> For buffers where each thread accesses its own index

// Instead of register(...) we can also use [[vk::binding(uint)]]

#pragma shader_stage(compute)

#ifndef _NBL_HLSL_WORKGROUP_SIZE_
#define _NBL_HLSL_WORKGROUP_SIZE_ 256
#endif

#include "../common.glsl"

#include "nbl/builtin/hlsl/workgroup/scratch_sz.hlsl"
#include "nbl/builtin/hlsl/glsl_compat/core.hlsl"
#include "nbl/builtin/hlsl/workgroup/ballot.hlsl"
#include "nbl/builtin/hlsl/subgroup/basic.hlsl"
#include "nbl/builtin/hlsl/shared_memory_accessor.hlsl"

struct Output {
	uint subgroupSize;
	uint output[BUFFER_DWORD_COUNT];
};

StructuredBuffer<uint> inputValue : register(t0); // read-only

RWStructuredBuffer<Output> outand : register(u1);
RWStructuredBuffer<Output> outxor : register(u2);
RWStructuredBuffer<Output> outor : register(u3);
RWStructuredBuffer<Output> outadd : register(u4);
RWStructuredBuffer<Output> outmul : register(u5);
RWStructuredBuffer<Output> outmin : register(u6);
RWStructuredBuffer<Output> outmax : register(u7);
RWStructuredBuffer<Output> outbitcount : register(u8);

template<uint32_t WGSZ,uint32_t SGSZ>
struct required_scratch_size : nbl::hlsl::workgroup::impl::trunc_geom_series<WGSZ,SGSZ> {};
static const uint arithmeticSz = required_scratch_size<_NBL_HLSL_WORKGROUP_SIZE_, nbl::hlsl::subgroup::MinSubgroupSize>::value;
static const uint32_t ballotSz = nbl::hlsl::workgroup::uballotBitfieldCount + 1;
static const uint32_t scratchSz = arithmeticSz + ballotSz;
groupshared uint32_t scratch[scratchSz];

template<uint32_t offset>
struct ScratchProxy
{
	uint get(uint ix)
	{
		return scratch[ix + offset];
	}

	void set(uint ix, uint value)
	{
		scratch[ix + offset] = value;
	}
	
	uint atomicAdd(in uint ix, uint data)
	{
		return nbl::hlsl::glsl::atomicAdd(scratch[ix + offset], data);
	}
	
	uint atomicOr(in uint ix, uint data)
	{
		return nbl::hlsl::glsl::atomicOr(scratch[ix + offset], data);
	}
};

struct SharedMemory
{
	nbl::hlsl::SharedMemoryAdaptor<ScratchProxy<0> > main;
	nbl::hlsl::SharedMemoryAdaptor<ScratchProxy<arithmeticSz> > broadcast;
};