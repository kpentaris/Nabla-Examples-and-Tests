# Examples and Tests

The Nabla Examples are documentation-by-example and building blocks for our future Continuous Integration GPU Integration Tests.

## Where can I find the makefiles or IDE projects/solutions?

Given an example in folder `XY.ExampleName`, CMake will generate either a target or a separate makefile/project/solution called `examplename` (no number, always lowercase).

Whenever CMake generates separate makefiles/solutions/projects, they will be generated in the `./examples_tests` under the build directory you supplied to CMake.

**Samples are meant to be built into the `./bin` directory in the source (its git-ignored) and invoked with that Current Working Directory.**

**WARNING:** If you're using an IDE different than Visual Studio you need to set the CWD correctly for when you start the example for Debugging!

**WARNING:** Only generation of IDE projects by standalone CMake is supported, we do not use or rely on IDE integrations of CMake.

## Maintenance Matrix

| Example                         |    MSVCx64Release    |    MSVCx64RWDI    |     MSVCx64Debug     |  Androidx86_64Release   |   Androidx86_64RWDI    |  Androidx86_64Debug   | Win32OpenGL | Win32OpenGLES* | Win32Vulkan | X11**OpenGL | X11**OpenGLES | X11**Vulkan | AndroidOpenGLES | AndroidVulkan |             RequiredCMakeOptions****              |
| ------------------------------- | :------------------: | :---------------: | :------------------: | :---------------------: | :--------------------: | :-------------------: | :---------: | :------------: | :---------: | :---------: | :-----------: | :---------: | :-------------: | :-----------: | :-----------------------------------------------: |
| 01.HelloWorld                   | ![][01_MSVC_Release] | ![][01_MSVC_RWDI] |  ![][01_MSVC_Debug]  | ![][01_Android_Release] |  ![][01_Android_RWDI]  | ![][01_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][Y]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][Y]      |    ![][S]     |                                                   |
| 02.ComputeShader                | ![][02_MSVC_Release] | ![][02_MSVC_RWDI] |  ![][02_MSVC_Debug]  | ![][02_Android_Release] |  ![][02_Android_RWDI]  | ![][02_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][Y]    |   ![][B]    |    ![][B]     |   ![][S]    |     ![][B]      |    ![][S]     |                                                   |
| 03.GPU_Mesh                     | ![][03_MSVC_Release] | ![][03_MSVC_RWDI] |  ![][03_MSVC_Debug]  | ![][03_Android_Release] |  ![][03_Android_RWDI]  | ![][03_Android_Debug] |   ![][W]    |     ![][W]     |   ![][W]    |   ![][W]    |    ![][W]     |   ![][W]    |     ![][W]      |    ![][W]     |                                                   |
| 04.Keyframe                     | ![][04_MSVC_Release] | ![][04_MSVC_RWDI] |  ![][04_MSVC_Debug]  | ![][04_Android_Release] |  ![][04_Android_RWDI]  | ![][04_Android_Debug] |   ![][S]    |     ![][S]     |   ![][S]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][S]      |    ![][S]     |                                                   |
| 05.NablaTutorialExample         | ![][05_MSVC_Release] | ![][05_MSVC_RWDI] |  ![][05_MSVC_Debug]  | ![][05_Android_Release] |  ![][05_Android_RWDI]  | ![][05_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][Y]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][S]      |    ![][S]     |                                                   |
| 06.MeshLoaders                  | ![][06_MSVC_Release] | ![][06_MSVC_RWDI] |  ![][06_MSVC_Debug]  | ![][06_Android_Release] |  ![][06_Android_RWDI]  | ![][06_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][Y]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][Y]      |    ![][Y]     |                                                   |
| 07.SubpassBaking                | ![][07_MSVC_Release] | ![][07_MSVC_RWDI] |  ![][07_MSVC_Debug]  | ![][07_Android_Release] |  ![][07_Android_RWDI]  | ![][07_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][Y]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][S]      |    ![][S]     |                                                   |
| 08.                             | ![][08_MSVC_Release] | ![][08_MSVC_RWDI] |  ![][08_MSVC_Debug]  | ![][08_Android_Release] |  ![][08_Android_RWDI]  | ![][08_Android_Debug] |   ![][NA]   |    ![][NA]     |   ![][NA]   |   ![][NA]   |    ![][NA]    |   ![][NA]   |     ![][NA]     |    ![][NA]    |                                                   |
| 09.ColorSpaceTest               | ![][09_MSVC_Release] | ![][09_MSVC_RWDI] |  ![][09_MSVC_Debug]  | ![][09_Android_Release] |  ![][09_Android_RWDI]  | ![][09_Android_Debug] |   ![][B]    |     ![][B]     |   ![][B]    |   ![][W]    |    ![][W]     |   ![][W]    |     ![][W]      |    ![][W]     |                                                   |
| 10.AllocatorTest                | ![][10_MSVC_Release] | ![][10_MSVC_RWDI] |  ![][10_MSVC_Debug]  | ![][10_Android_Release] |  ![][10_Android_RWDI]  | ![][10_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][Y]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][N]      |    ![][N]     |                                                   |
| 11.LoDSystem                    | ![][11_MSVC_Release] | ![][11_MSVC_RWDI] |  ![][11_MSVC_Debug]  | ![][11_Android_Release] |  ![][11_Android_RWDI]  | ![][11_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][B]    |   ![][S]    |    ![][N]     |   ![][S]    |     ![][N]      |    ![][S]     |                                                   |
| 12.glTF                         | ![][12_MSVC_Release] | ![][12_MSVC_RWDI] |  ![][12_MSVC_Debug]  | ![][12_Android_Release] |  ![][12_Android_RWDI]  | ![][12_Android_Debug] |   ![][W]    |     ![][N]     |   ![][W]    |   ![][W]    |    ![][N]     |   ![][W]    |     ![][N]      |    ![][W]     |             COMPILE_WITH_GLTF_LOADER              |
| 13.                             | ![][13_MSVC_Release] | ![][13_MSVC_RWDI] |  ![][13_MSVC_Debug]  | ![][13_Android_Release] |  ![][13_Android_RWDI]  | ![][13_Android_Debug] |   ![][NA]   |    ![][NA]     |   ![][NA]   |   ![][NA]   |    ![][NA]    |   ![][NA]   |     ![][NA]     |    ![][NA]    |                                                   |
| 14.ComputeScan                  | ![][14_MSVC_Release] | ![][14_MSVC_RWDI] |  ![][14_MSVC_Debug]  | ![][14_Android_Release] |  ![][14_Android_RWDI]  | ![][14_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][B]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][S]      |    ![][S]     |                                                   |
| 15.                             | ![][15_MSVC_Release] | ![][15_MSVC_RWDI] |  ![][15_MSVC_Debug]  | ![][15_Android_Release] |  ![][15_Android_RWDI]  | ![][15_Android_Debug] |   ![][NA]   |    ![][NA]     |   ![][NA]   |   ![][NA]   |    ![][NA]    |   ![][NA]   |     ![][NA]     |    ![][NA]    |                                                   |
| 16.OrderIndependentTransparency | ![][16_MSVC_Release] | ![][16_MSVC_RWDI] |  ![][16_MSVC_Debug]  | ![][16_Android_Release] |  ![][16_Android_RWDI]  | ![][16_Android_Debug] |   ![][B]    |     ![][B]     |   ![][B]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][S]      |    ![][S]     |                                                   |
| 17.SimpleBulletIntegration      | ![][17_MSVC_Release] | ![][17_MSVC_RWDI] |  ![][17_MSVC_Debug]  | ![][17_Android_Release] |  ![][17_Android_RWDI]  | ![][17_Android_Debug] |   ![][B]    |     ![][N]     |   ![][B]    |   ![][S]    |    ![][N]     |   ![][S]    |     ![][N]      |    ![][N]     |                   BUILD_BULLET                    |
| 18.MitsubaLoader                | ![][18_MSVC_Release] | ![][18_MSVC_RWDI] |  ![][18_MSVC_Debug]  | ![][18_Android_Release] |  ![][18_Android_RWDI]  | ![][18_Android_Debug] |   ![][S]    |     ![][N]     |   ![][S]    |   ![][S]    |    ![][N]     |   ![][S]    |     ![][N]      |    ![][N]     |               BUILD_MITSUBA_LOADER                |
| 19.                             | ![][19_MSVC_Release] | ![][19_MSVC_RWDI] |  ![][19_MSVC_Debug]  | ![][19_Android_Release] |  ![][19_Android_RWDI]  | ![][19_Android_Debug] |   ![][NA]   |    ![][NA]     |   ![][NA]   |   ![][NA]   |    ![][NA]    |   ![][NA]   |     ![][NA]     |    ![][NA]    |                                                   |
| 20.Megatexture                  | ![][20_MSVC_Release] | ![][20_MSVC_RWDI] |  ![][20_MSVC_Debug]  | ![][20_Android_Release] |  ![][20_Android_RWDI]  | ![][20_Android_Debug] |   ![][W]    |     ![][W]     |   ![][W]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][N]      |    ![][S]     |                                                   |
| 21.DynamicTextureIndexing       | ![][21_MSVC_Release] | ![][21_MSVC_RWDI] |  ![][21_MSVC_Debug]  | ![][21_Android_Release] |  ![][21_Android_RWDI]  | ![][21_Android_Debug] |   ![][B]    |     ![][B]     |   ![][B]    |   ![][S]    |    ![][N]     |   ![][S]    |     ![][N]      |    ![][S]     |                                                   |
| 22.RaytracedAO                  | ![][22_MSVC_Release] | ![][22_MSVC_RWDI] |  ![][22_MSVC_Debug]  | ![][22_Android_Release] |  ![][22_Android_RWDI]  | ![][22_Android_Debug] |   ![][N]    |     ![][N]     |   ![][W]    |   ![][N]    |    ![][N]     |   ![][W]    |     ![][N]      |    ![][N]     |               BUILD_MITSUBA_LOADER                |
| 23.Autoexposure                 | ![][23_MSVC_Release] | ![][23_MSVC_RWDI] |  ![][23_MSVC_Debug]  | ![][23_Android_Release] |  ![][23_Android_RWDI]  | ![][23_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][Y]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][N]      |    ![][S]     |                                                   |
| 24.                             | ![][24_MSVC_Release] | ![][24_MSVC_RWDI] |  ![][24_MSVC_Debug]  | ![][24_Android_Release] |  ![][24_Android_RWDI]  | ![][24_Android_Debug] |   ![][NA]   |    ![][NA]     |   ![][NA]   |   ![][NA]   |    ![][NA]    |   ![][NA]   |     ![][NA]     |    ![][NA]    |                                                   |
| 25.Blur                         | ![][25_MSVC_Release] | ![][25_MSVC_RWDI] |  ![][25_MSVC_Debug]  | ![][25_Android_Release] |  ![][25_Android_RWDI]  | ![][25_Android_Debug] |   ![][S]    |     ![][N]     |   ![][S]    |   ![][S]    |    ![][N]     |   ![][S]    |     ![][N]      |    ![][S]     |                                                   |
| 26.                             | ![][26_MSVC_Release] | ![][26_MSVC_RWDI] |  ![][26_MSVC_Debug]  | ![][26_Android_Release] |  ![][26_Android_RWDI]  | ![][26_Android_Debug] |   ![][NA]   |    ![][NA]     |   ![][NA]   |   ![][NA]   |    ![][NA]    |   ![][NA]   |     ![][NA]     |    ![][NA]    |                                                   |
| 27.PLYSTLDemo                   | ![][27_MSVC_Release] | ![][27_MSVC_RWDI] |  ![][27_MSVC_Debug]  | ![][27_Android_Release] |  ![][27_Android_RWDI]  | ![][27_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][B]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][N]      |    ![][N]     | COMPILE_WITH_STL_LOADER & COMPILE_WITH_PLY_LOADER |
| 28.                             | ![][28_MSVC_Release] | ![][28_MSVC_RWDI] |  ![][28_MSVC_Debug]  | ![][28_Android_Release] |  ![][28_Android_RWDI]  | ![][28_Android_Debug] |   ![][NA]   |    ![][NA]     |   ![][NA]   |   ![][NA]   |    ![][NA]    |   ![][NA]   |     ![][NA]     |    ![][NA]    |                                                   |
| 29.SpecializationConstants      | ![][29_MSVC_Release] | ![][29_MSVC_RWDI] |  ![][29_MSVC_Debug]  | ![][29_Android_Release] |  ![][29_Android_RWDI]  | ![][29_Android_Debug] |   ![][B]    |     ![][B]     |   ![][B]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][N]      |    ![][S]     |                                                   |
| 30.                             | ![][30_MSVC_Release] | ![][30_MSVC_RWDI] |  ![][30_MSVC_Debug]  | ![][30_Android_Release] |  ![][30_Android_RWDI]  | ![][30_Android_Debug] |   ![][NA]   |    ![][NA]     |   ![][NA]   |   ![][NA]   |    ![][NA]    |   ![][NA]   |     ![][NA]     |    ![][NA]    |                                                   |
| 31.                             | ![][31_MSVC_Release] | ![][31_MSVC_RWDI] |  ![][31_MSVC_Debug]  | ![][31_Android_Release] |  ![][31_Android_RWDI]  | ![][31_Android_Debug] |   ![][NA]   |    ![][NA]     |   ![][NA]   |   ![][NA]   |    ![][NA]    |   ![][NA]   |     ![][NA]     |    ![][NA]    |                                                   |
| 32.                             | ![][32_MSVC_Release] | ![][32_MSVC_RWDI] |  ![][32_MSVC_Debug]  | ![][32_Android_Release] |  ![][32_Android_RWDI]  | ![][32_Android_Debug] |   ![][NA]   |    ![][NA]     |   ![][NA]   |   ![][NA]   |    ![][NA]    |   ![][NA]   |     ![][NA]     |    ![][NA]    |                                                   |
| 33.Draw3DLine                   | ![][33_MSVC_Release] | ![][33_MSVC_RWDI] |  ![][33_MSVC_Debug]  | ![][33_Android_Release] |  ![][33_Android_RWDI]  | ![][33_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][Y]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][S]      |    ![][S]     |                                                   |
| 34.LRUCacheUnitTest             | ![][34_MSVC_Release] | ![][34_MSVC_RWDI] |  ![][34_MSVC_Debug]  | ![][34_Android_Release] |  ![][34_Android_RWDI]  | ![][34_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][Y]    |   ![][Y]    |    ![][Y]     |   ![][Y]    |     ![][N]      |    ![][N]     |                                                   |
| 35.GeometryCreator              | ![][35_MSVC_Release] | ![][35_MSVC_RWDI] | ![][3504_MSVC_Debug] | ![][35_Android_Release] |  ![][35_Android_RWDI]  | ![][35_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][Y]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][N]      |    ![][S]     |                                                   |
| 36.CUDAInterop                  | ![][36_MSVC_Release] | ![][36_MSVC_RWDI] | ![][3604_MSVC_Debug] | ![][36_Android_Release] |  ![][36_Android_RWDI]  | ![][36_Android_Debug] |   ![][N]    |     ![][N]     |   ![][W]    |   ![][N]    |    ![][N]     |   ![][W]    |     ![][N]      |    ![][N]     |                 COMPILE_WITH_CUDA                 |
| 37.                             | ![][37_MSVC_Release] | ![][37_MSVC_RWDI] |  ![][37_MSVC_Debug]  | ![][37_Android_Release] |  ![][37_Android_RWDI]  | ![][37_Android_Debug] |   ![][NA]   |    ![][NA]     |   ![][NA]   |   ![][NA]   |    ![][NA]    |   ![][NA]   |     ![][NA]     |    ![][NA]    |                                                   |
| 38.EXRSplit                     | ![][38_MSVC_Release] | ![][38_MSVC_RWDI] |  ![][38_MSVC_Debug]  | ![][38_Android_Release] |  ![][38_Android_RWDI]  | ![][38_Android_Debug] |   ![][S]    |     ![][S]     |   ![][S]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][N]      |    ![][N]     |                                                   |
| 39.DenoiserTonemapper           | ![][39_MSVC_Release] | ![][39_MSVC_RWDI] |  ![][39_MSVC_Debug]  | ![][39_Android_Release] |  ![][39_Android_RWDI]  | ![][39_Android_Debug] |   ![][N]    |     ![][N]     |   ![][W]    |   ![][N]    |    ![][N]     |   ![][W]    |     ![][N]      |    ![][N]     |      COMPILE_WITH_CUDA & COMPILE_WITH_OPTIX       |
| 40.GLITest                      | ![][40_MSVC_Release] | ![][40_MSVC_RWDI] |  ![][40_MSVC_Debug]  | ![][40_Android_Release] |  ![][40_Android_RWDI]  | ![][40_Android_Debug] |   ![][S]    |     ![][S]     |   ![][S]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][N]      |    ![][S]     |              COMPILE_WITH_GLI_LOADER              |
| 41.VisibilityBuffer             | ![][41_MSVC_Release] | ![][41_MSVC_RWDI] |  ![][41_MSVC_Debug]  | ![][41_Android_Release] |  ![][41_Android_RWDI]  | ![][41_Android_Debug] |   ![][S]    |     ![][S]     |   ![][S]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][N]      |    ![][N]     |                                                   |
| 42.FragmentShaderPathTracer     | ![][42_MSVC_Release] | ![][42_MSVC_RWDI] |  ![][42_MSVC_Debug]  | ![][42_Android_Release] | ![][4204_Android_RWDI] | ![][42_Android_Debug] |   ![][B]    |     ![][B]     |   ![][Y]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][S]      |    ![][S]     |                                                   |
| 43.SumAndCDFFilters             | ![][43_MSVC_Release] | ![][43_MSVC_RWDI] |  ![][43_MSVC_Debug]  | ![][43_Android_Release] |  ![][43_Android_RWDI]  | ![][43_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][Y]    |   ![][S]    |    ![][N]     |   ![][S]    |     ![][N]      |    ![][N]     |                                                   |
| 44.LevelCurveExtraction         | ![][44_MSVC_Release] | ![][44_MSVC_RWDI] |  ![][44_MSVC_Debug]  | ![][44_Android_Release] |  ![][44_Android_RWDI]  | ![][44_Android_Debug] |   ![][S]    |     ![][N]     |   ![][S]    |   ![][S]    |    ![][N]     |   ![][S]    |     ![][N]      |    ![][N]     |                                                   |
| 45.BRDFEvalTest                 | ![][45_MSVC_Release] | ![][45_MSVC_RWDI] |  ![][45_MSVC_Debug]  | ![][45_Android_Release] |  ![][45_Android_RWDI]  | ![][45_Android_Debug] |   ![][S]    |     ![][S]     |   ![][S]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][N]      |    ![][S]     |                                                   |
| 46.SamplingValidation           | ![][46_MSVC_Release] | ![][46_MSVC_RWDI] |  ![][46_MSVC_Debug]  | ![][46_Android_Release] |  ![][46_Android_RWDI]  | ![][46_Android_Debug] |   ![][S]    |     ![][S]     |   ![][S]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][N]      |    ![][S]     |                                                   |
| 47.DerivMapTest                 | ![][47_MSVC_Release] | ![][47_MSVC_RWDI] | ![][4704_MSVC_Debug] | ![][47_Android_Release] |  ![][47_Android_RWDI]  | ![][47_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][B]    |   ![][S]    |    ![][N]     |   ![][S]    |     ![][N]      |    ![][N]     |                                                   |
| 48.ArithmeticUnitTest           | ![][48_MSVC_Release] | ![][48_MSVC_RWDI] |  ![][48_MSVC_Debug]  | ![][48_Android_Release] |  ![][48_Android_RWDI]  | ![][48_Android_Debug] |   ![][Y]    |     ![][B]     |   ![][B]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][N]      |    ![][S]     |                                                   |
| 49.ComputeFFT                   | ![][49_MSVC_Release] | ![][49_MSVC_RWDI] |  ![][49_MSVC_Debug]  | ![][49_Android_Release] |  ![][49_Android_RWDI]  | ![][49_Android_Debug] |   ![][S]    |     ![][N]     |   ![][S]    |   ![][S]    |    ![][N]     |   ![][S]    |     ![][N]      |    ![][N]     |                                                   |
| 50.NewAPITest                   | ![][50_MSVC_Release] | ![][50_MSVC_RWDI] |  ![][50_MSVC_Debug]  | ![][50_Android_Release] |  ![][50_Android_RWDI]  | ![][50_Android_Debug] |   ![][W]    |     ![][W]     |   ![][W]    |   ![][W]    |    ![][W]     |   ![][W]    |     ![][W]      |    ![][W]     |                                                   |
| 51.RadixSort                    | ![][51_MSVC_Release] | ![][51_MSVC_RWDI] |  ![][51_MSVC_Debug]  | ![][51_Android_Release] | ![][5104_Android_RWDI] | ![][51_Android_Debug] |   ![][W]    |     ![][N]     |   ![][W]    |   ![][W]    |    ![][N]     |   ![][W]    |     ![][N]      |    ![][W]     |                                                   |
| 52.SystemTest                   | ![][52_MSVC_Release] | ![][52_MSVC_RWDI] |  ![][52_MSVC_Debug]  | ![][52_Android_Release] |  ![][52_Android_RWDI]  | ![][52_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][Y]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][S]      |    ![][S]     |                                                   |
| 53.ComputeShaders               | ![][53_MSVC_Release] | ![][53_MSVC_RWDI] |  ![][53_MSVC_Debug]  | ![][53_Android_Release] |  ![][53_Android_RWDI]  | ![][53_Android_Debug] |   ![][B]    |     ![][B]     |   ![][B]    |   ![][S]    |    ![][N]     |   ![][S]    |     ![][N]      |    ![][S]     |                                                   |
| 54.Transformations              | ![][54_MSVC_Release] | ![][54_MSVC_RWDI] |  ![][54_MSVC_Debug]  | ![][54_Android_Release] |  ![][54_Android_RWDI]  | ![][54_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][B]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][S]      |    ![][S]     |                                                   |
| 55.RGB18E7S3                    | ![][55_MSVC_Release] | ![][55_MSVC_RWDI] |  ![][55_MSVC_Debug]  | ![][55_Android_Release] |  ![][55_Android_RWDI]  | ![][55_Android_Debug] |   ![][Y]    |     ![][Y]     |   ![][Y]    |   ![][S]    |    ![][S]     |   ![][S]    |     ![][N]      |    ![][N]     |                                                   |
| 56.RayQuery                     | ![][56_MSVC_Release] | ![][56_MSVC_RWDI] |  ![][56_MSVC_Debug]  | ![][56_Android_Release] |  ![][56_Android_RWDI]  | ![][56_Android_Debug] |   ![][N]    |     ![][N]     |   ![][Y]    |   ![][N]    |    ![][N]     |   ![][S]    |     ![][N]      |    ![][S]     |                                                   |
| 57.AndroidSample                | ![][57_MSVC_Release] | ![][57_MSVC_RWDI] |  ![][57_MSVC_Debug]  | ![][57_Android_Release] |  ![][57_Android_RWDI]  | ![][57_Android_Debug] |   ![][N]    |     ![][N]     |   ![][N]    |   ![][N]    |    ![][N]     |   ![][N]    |     ![][S]      |    ![][S]     |                                                   |
| 58.MediaUnpackingOnAndroid      | ![][58_MSVC_Release] | ![][58_MSVC_RWDI] |  ![][58_MSVC_Debug]  | ![][58_Android_Release] |  ![][58_Android_RWDI]  | ![][58_Android_Debug] |   ![][N]    |     ![][N]     |   ![][N]    |   ![][N]    |    ![][N]     |   ![][N]    |     ![][Y]      |    ![][Y]     |                                                   |
| 59.                             | ![][59_MSVC_Release] | ![][59_MSVC_RWDI] |  ![][59_MSVC_Debug]  | ![][59_Android_Release] |  ![][59_Android_RWDI]  | ![][59_Android_Debug] |   ![][NA]   |    ![][NA]     |   ![][NA]   |   ![][NA]   |    ![][NA]    |   ![][NA]   |     ![][NA]     |    ![][NA]    |                                                   |
| 60.ClusteredRendering           | ![][60_MSVC_Release] | ![][60_MSVC_RWDI] |  ![][60_MSVC_Debug]  | ![][60_Android_Release] |  ![][60_Android_RWDI]  | ![][60_Android_Debug] |   ![][W]    |     ![][N]     |   ![][W]    |   ![][W]    |    ![][N]     |   ![][W]    |     ![][N]      |    ![][N]     |                                                   |

#### Legend

![][Y] Already Works

![][B] Has a known bug

![][W] Work-In-Progress, sample logic not complete or temporarily modified

![][S] Intended to be Supported (requires some work to port after an API change)

![][N] No support

_Examples numbered 00 are provisional and are not part of the example suite._

#### Notes

`*` Only Nvidia provides a working GLES 3.1 driver with OES_texture_view on Windows, so we only test there.

`**` Needs the Xcb implementation of the `ui::` namespace to be complete.

`***` Only x86_64 architecture supported for Android builds, also NBL_BUILD_ANDROID is required.

`****` NBL_BUILD_EXAMPLES is needed for any example to build!

[01_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dhelloworld%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[02_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dcomputeshader%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[03_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dgpu_mesh%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[04_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dkeyframe%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[05_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dnablatutorialexample%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[06_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dmeshloaders%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[07_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dsubpassbaking%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[08_MSVC_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[09_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dcolorspacetest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[10_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dallocatortest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[11_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dlodsystem%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[12_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dgltf%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[13_MSVC_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[14_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dcomputescan%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[15_MSVC_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[16_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dorderindependenttransparency%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[17_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dsimplebulletintegration%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[18_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dmitsubaloader%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[19_MSVC_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[20_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dmegatexture%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[21_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Ddynamictextureindexing%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[22_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Draytracedao%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[23_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dautoexposure%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[24_MSVC_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[25_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dblur%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[26_MSVC_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[27_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dplystldemo%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[28_MSVC_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[29_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dplystldemo%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[30_MSVC_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[31_MSVC_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[32_MSVC_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[33_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Ddraw3dline%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[34_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dlrucacheunittest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[35_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dgeometrycreator%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[36_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dcudainterop%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[37_MSVC_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[38_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dexrsplit%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[39_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Ddenoisertonemapper%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[40_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dglitest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[41_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dvisibilitybuffer%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[42_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dfragmentshaderpathtracer%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[43_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dsumandcdffilters%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[44_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dlevelcurveextraction%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[45_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dbrdfevaltest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[46_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dsamplingvalidation%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[47_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dderivmaptest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[48_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Darithmeticunittest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[49_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dcomputefft%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[50_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dnewapitest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[51_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dradixsort%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[52_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dsystemtest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[53_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dcomputeshaders%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[54_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dtransformations%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[55_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Drgb18e7s3%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[56_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Drayquery%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[57_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dandroidsample%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[58_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dmediaunpackingonandroid%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[59_MSVC_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[60_MSVC_Release]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelease%2CDEVSH_EXAMPLES%3Dclusteredrendering%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows



=======================



[01_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dhelloworld%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[02_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dcomputeshader%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[03_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dgpu_mesh%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[04_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dkeyframe%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[05_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dnablatutorialexample%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[06_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dmeshloaders%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[07_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dsubpassbaking%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[08_MSVC_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[09_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dcolorspacetest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[10_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dallocatortest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[11_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dlodsystem%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[12_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dgltf%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[13_MSVC_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[14_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dcomputescan%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[15_MSVC_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[16_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dorderindependenttransparency%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[17_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dsimplebulletintegration%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[18_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dmitsubaloader%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[19_MSVC_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[20_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dmegatexture%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[21_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Ddynamictextureindexing%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[22_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Draytracedao%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[23_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dautoexposure%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[24_MSVC_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[25_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dblur%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[26_MSVC_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[27_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dplystldemo%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[28_MSVC_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[29_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dspecializationconstants%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[30_MSVC_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[31_MSVC_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[32_MSVC_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[33_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Ddraw3dline%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[34_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dlrucacheunittest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[35_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dgeometrycreator%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[36_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dcudainterop%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[37_MSVC_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[38_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dexrsplit%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[39_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Ddenoisertonemapper%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[40_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dglitest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[41_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dvisibilitybuffer%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[42_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dfragmentshaderpathtracer%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[43_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dsumandcdffilters%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[44_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dlevelcurveextraction%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[45_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dbrdfevaltest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[46_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dsamplingvalidation%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[47_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dderivmaptest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[48_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Darithmeticunittest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[49_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dcomputefft%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[50_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dnewapitest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[51_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dradixsort%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[52_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dsystemtest%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[53_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dcomputeshaders%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[54_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dtransformations%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[55_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Drgb18e7s3%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[56_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Drayquery%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[57_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dandroidsample%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[58_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dmediaunpackingonandroid%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows
[59_MSVC_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[60_MSVC_RWDI]: https://ci.devsh.eu/buildStatus/icon?job=BuildExamples%2FDEVSH_CONFIGURATIONS%3DRelWithDebInfo%2CDEVSH_EXAMPLES%3Dclusteredrendering%2CDEVSH_NODES%3Dpredator15%2CDEVSH_OS%3DWindows



==================



[01_MSVC_Debug]: t
[02_MSVC_Debug]: t
[03_MSVC_Debug]: t
[04_MSVC_Debug]: t
[05_MSVC_Debug]: t
[06_MSVC_Debug]: t
[07_MSVC_Debug]: t
[08_MSVC_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[09_MSVC_Debug]: t
[10_MSVC_Debug]: t
[11_MSVC_Debug]: t
[12_MSVC_Debug]: t
[13_MSVC_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[14_MSVC_Debug]: t
[15_MSVC_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[16_MSVC_Debug]: t
[17_MSVC_Debug]: t
[18_MSVC_Debug]: t
[19_MSVC_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[20_MSVC_Debug]: t
[21_MSVC_Debug]: t
[22_MSVC_Debug]: t
[23_MSVC_Debug]: t
[24_MSVC_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[25_MSVC_Debug]: t
[26_MSVC_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[27_MSVC_Debug]: t
[28_MSVC_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[29_MSVC_Debug]: t
[30_MSVC_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[31_MSVC_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[32_MSVC_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[33_MSVC_Debug]: t
[34_MSVC_Debug]: t
[35_MSVC_Debug]: t
[36_MSVC_Debug]: t
[37_MSVC_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[38_MSVC_Debug]: t
[39_MSVC_Debug]: t
[40_MSVC_Debug]: t
[41_MSVC_Debug]: t
[42_MSVC_Debug]: t
[43_MSVC_Debug]: t
[44_MSVC_Debug]: t
[45_MSVC_Debug]: t
[46_MSVC_Debug]: t
[47_MSVC_Debug]: t
[48_MSVC_Debug]: t
[49_MSVC_Debug]: t
[50_MSVC_Debug]: t
[51_MSVC_Debug]: t
[52_MSVC_Debug]: t
[53_MSVC_Debug]: t
[54_MSVC_Debug]: t
[55_MSVC_Debug]: t
[56_MSVC_Debug]: t
[57_MSVC_Debug]: t
[58_MSVC_Debug]: t
[59_MSVC_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[60_MSVC_Debug]: t





666969696969696969696699696969696969696



[01_Android_Release]: t
[02_Android_Release]: t
[03_Android_Release]: t
[04_Android_Release]: t
[05_Android_Release]: t
[06_Android_Release]: t
[07_Android_Release]: t
[08_Android_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[09_Android_Release]: t
[10_Android_Release]: t
[11_Android_Release]: t
[12_Android_Release]: t
[13_Android_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[14_Android_Release]: t
[15_Android_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[16_Android_Release]: t
[17_Android_Release]: t
[18_Android_Release]: t
[19_Android_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[20_Android_Release]: t
[21_Android_Release]: t
[22_Android_Release]: t
[23_Android_Release]: t
[24_Android_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[25_Android_Release]: t
[26_Android_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[27_Android_Release]: t
[28_Android_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[29_Android_Release]: t
[30_Android_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[31_Android_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[32_Android_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[33_Android_Release]: t
[34_Android_Release]: t
[35_Android_Release]: t
[36_Android_Release]: t
[37_Android_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[38_Android_Release]: t
[39_Android_Release]: t
[40_Android_Release]: t
[41_Android_Release]: t
[42_Android_Release]: t
[43_Android_Release]: t
[44_Android_Release]: t
[45_Android_Release]: t
[46_Android_Release]: t
[47_Android_Release]: t
[48_Android_Release]: t
[49_Android_Release]: t
[50_Android_Release]: t
[51_Android_Release]: t
[52_Android_Release]: t
[53_Android_Release]: t
[54_Android_Release]: t
[55_Android_Release]: t
[56_Android_Release]: t
[57_Android_Release]: t
[58_Android_Release]: t
[59_Android_Release]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[60_Android_Release]: t



=======================



[01_Android_RWDI]: t
[02_Android_RWDI]: t
[03_Android_RWDI]: t
[04_Android_RWDI]: t
[05_Android_RWDI]: t
[06_Android_RWDI]: t
[07_Android_RWDI]: t
[08_Android_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[09_Android_RWDI]: t
[10_Android_RWDI]: t
[11_Android_RWDI]: t
[12_Android_RWDI]: t
[13_Android_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[14_Android_RWDI]: t
[15_Android_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[16_Android_RWDI]: t
[17_Android_RWDI]: t
[18_Android_RWDI]: t
[19_Android_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[20_Android_RWDI]: t
[21_Android_RWDI]: t
[22_Android_RWDI]: t
[23_Android_RWDI]: t
[24_Android_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[25_Android_RWDI]: t
[26_Android_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[27_Android_RWDI]: t
[28_Android_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[29_Android_RWDI]: t
[30_Android_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[31_Android_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[32_Android_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[33_Android_RWDI]: t
[34_Android_RWDI]: t
[35_Android_RWDI]: t
[36_Android_RWDI]: t
[37_Android_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[38_Android_RWDI]: t
[39_Android_RWDI]: t
[40_Android_RWDI]: t
[41_Android_RWDI]: t
[42_Android_RWDI]: t
[43_Android_RWDI]: t
[44_Android_RWDI]: t
[45_Android_RWDI]: t
[46_Android_RWDI]: t
[47_Android_RWDI]: t
[48_Android_RWDI]: t
[49_Android_RWDI]: t
[50_Android_RWDI]: t
[51_Android_RWDI]: t
[52_Android_RWDI]: t
[53_Android_RWDI]: t
[54_Android_RWDI]: t
[55_Android_RWDI]: t
[56_Android_RWDI]: t
[57_Android_RWDI]: t
[58_Android_RWDI]: t
[59_Android_RWDI]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[60_Android_RWDI]: t



==================



[01_Android_Debug]: t
[02_Android_Debug]: t
[03_Android_Debug]: t
[04_Android_Debug]: t
[05_Android_Debug]: t
[06_Android_Debug]: t
[07_Android_Debug]: t
[08_Android_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[09_Android_Debug]: t
[10_Android_Debug]: t
[11_Android_Debug]: t
[12_Android_Debug]: t
[13_Android_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[14_Android_Debug]: t
[15_Android_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[16_Android_Debug]: t
[17_Android_Debug]: t
[18_Android_Debug]: t
[19_Android_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[20_Android_Debug]: t
[21_Android_Debug]: t
[22_Android_Debug]: t
[23_Android_Debug]: t
[24_Android_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[25_Android_Debug]: t
[26_Android_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[27_Android_Debug]: t
[28_Android_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[29_Android_Debug]: t
[30_Android_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[31_Android_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[32_Android_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[33_Android_Debug]: t
[34_Android_Debug]: t
[35_Android_Debug]: t
[36_Android_Debug]: t
[37_Android_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[38_Android_Debug]: t
[39_Android_Debug]: t
[40_Android_Debug]: t
[41_Android_Debug]: t
[42_Android_Debug]: t
[43_Android_Debug]: t
[44_Android_Debug]: t
[45_Android_Debug]: t
[46_Android_Debug]: t
[47_Android_Debug]: t
[48_Android_Debug]: t
[49_Android_Debug]: t
[50_Android_Debug]: t
[51_Android_Debug]: t
[52_Android_Debug]: t
[53_Android_Debug]: t
[54_Android_Debug]: t
[55_Android_Debug]: t
[56_Android_Debug]: t
[57_Android_Debug]: t
[58_Android_Debug]: t
[59_Android_Debug]: https://img.shields.io/badge/free%20slot-n%2Fa-red
[60_Android_Debug]: t



[Y]: https://img.shields.io/badge/status-Y-brightgreen
[B]: https://img.shields.io/badge/status-B-yellow
[W]: https://img.shields.io/badge/status-W-orange
[S]: https://img.shields.io/badge/status-S-blue
[N]: https://img.shields.io/badge/status-N-black
[NA]: https://img.shields.io/badge/free%20slot-n%2Fa-red



