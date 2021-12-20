# vcuda-controller

[![Build Status](https://travis-ci.org/tkestack/vcuda-controller.svg?branch=master)](https://travis-ci.org/tkestack/vcuda-controller)
[![Total alerts](https://img.shields.io/lgtm/alerts/g/tkestack/vcuda-controller.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/tkestack/vcuda-controller/alerts/)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/tkestack/vcuda-controller.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/tkestack/vcuda-controller/context:cpp)

This project is a wrapper of NVIDIA driver library, it's a component
of [gpu-manager](https://github.com/tkestack/gpu-manager) which makes Kubernetes can not only run more than one Pod on
the same GPU, but also give QoS guaranteed to each Pod. For more details, please refer to our
paper [here](https://ieeexplore.ieee.org/abstract/document/8672318).

## Build

```
IMAGE_FILE=<your image name without version> ./build-img.sh
```

## CUDA/GPU support information

CUDA 11.5.1 and before are supported

Any architecture of GPU after Kepler are supported