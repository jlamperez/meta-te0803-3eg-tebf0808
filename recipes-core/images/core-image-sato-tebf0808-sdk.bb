DESCRIPTION = "Image with Sato, a mobile environment and visual style for \
mobile devices. The image supports X11 with a Sato theme, Pimlico \
applications, and contains terminal, editor, and file manager plus meta-toolchain, \
development headers and libraries to form a standalone SDK."

IMAGE_FEATURES += "splash package-management x11-base x11-sato ssh-server-dropbear hwcodecs  \
                   dev-pkgs tools-sdk tools-debug eclipse-debug tools-profile tools-testapps \
                   debug-tweaks ssh-server-openssh"

LICENSE = "MIT"

inherit core-image

TOOLCHAIN_HOST_TASK_append = " nativesdk-intltool nativesdk-glib-2.0"
TOOLCHAIN_HOST_TASK_remove_task-populate-sdk-ext = " nativesdk-intltool nativesdk-glib-2.0"

inherit extrausers
IMAGE_LINGUAS = " "

IMAGE_INSTALL = "\
                kernel-devsrc \
                kernel-modules \
                busybox \
                e2fsprogs \
                e2fsprogs-mke2fs \
                e2fsprogs-e2fsck \
                i2c-tools \
                mtd-utils \
                usbutils \
                alsa-tools \
                alsa-utils \
                alsa-utils-alsactl \
                alsa-utils-alsamixer \
                alsa-utils-speakertest \
                alsa-utils-aplay \
                file \
                pciutils \
                libpci \
                run-postinsts \
                alsa-state \
                alsa-utils-scripts \
                packagegroup-core-boot \
                tcf-agent \
                alsa-plugins \
                adau1761init \
                startup \
                devmem2 \
                libstdc++-dev \
                libstdc++ \
"

EXTRA_USERS_PARAMS = "usermod -P root root;"

SOURCE_MIRROR_URL ?= "file://~/Escritorio/mali"
INHERIT += "own-mirrors"
