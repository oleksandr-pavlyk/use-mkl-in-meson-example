# Example to illustrate using MKL with meson in conda

```bash
conda env create -f environment.yaml
conda activate meson_build_example
# apply work-around for missing openmp.pc
cp openmp.pc $CONDA_PREFIX/lib/pkgconfig/
meson setup build
cd build
meson install
./toy_use_mkl
```

Check that `ldd toy_use_mkl` does link to MKL libraries in the conda environment.
Setting `PKG_CONFIG_PATH` ensure that it is true even if oneAPI is installed on the machine.

The output:

```
$ ./toy_use_mkl
Intel(R) oneAPI Math Kernel Library Version 2023.2-Product Build 20230613 for Intel(R) 64 architecture applications

Computed dot product value: 4.000000e+00
Expected dot product value: 4.000000e+00
```

N.B.: Note that `environment.yaml` specifies the build number of mkl-devel to install.

This needs to be done because there is an older (in timestamp) build of mkl-devel with higher
build number, and that package installs pkgconfig/ files in an incorrect location.
