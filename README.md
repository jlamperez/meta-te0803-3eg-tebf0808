This README file contains information on the contents of the
te0803-3eg-tebf0808 layer.

Please see the corresponding sections below for details.


Dependencies
============

This layer depends on:

```
  URI: git://git.yoctoproject.org/poky.git
  branch: rocko

  URI: https://github.com/Xilinx/meta-xilinx.git
  layers: meta-xilinx-bsp
  branch: rocko
```

Patches
=======

Maintainer: Jorge Lamperez <jlamperez10@gmail.com>


Table of Contents
=================

  I. Adding the te0803-3eg-tebf0808 layer to your build
 II. Misc


I. Adding the te0803-3eg-tebf0808 layer to your build
=================================================

In order to use this layer, you need to make the build system aware of
it.

Assuming the te0803-3eg-tebf0808 layer exists at the top-level of your
yocto build tree, you can add it to the build system by adding the
location of the te0803-3eg-tebf0808 layer to bblayers.conf, along with any
other layers needed. e.g.:

```
  BBLAYERS ?= " \
    /path/to/yocto/meta \
    /path/to/yocto/meta-poky \
    /path/to/yocto/meta-yocto-bsp \
    /path/to/poky/meta-xilinx/meta-xilinx-bsp \
    /path/to/yocto/te0803-3eg-tebf0808 \
    "
```

II. Misc
========

```
MACHINE ??="te0803-3eg-tebf0808-zynqmp"
```

```
#
# Parallel thread execution
#
CONFIG_YOCTO_BB_NUMBER_THREADS="8"
CONFIG_YOCTO_PARALLEL_MAKE="-j 8"
```

Launch
=========

```
bitbake core-image-tebf0808
```
or
```
bitbake core-image-minimal
```

More Info
=========
See the [Wiki](https://github.com/jlamperez/meta-te0803-3eg-tebf0808/wiki)
