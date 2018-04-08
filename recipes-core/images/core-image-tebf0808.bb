DESCRIPTION = "Image definition for Trenz te0803-3eg-tebf0808 Starter kit"
LICENSE = "MIT"

inherit core-image

COMMON_FEATURES = " \
    ssh-server-dropbear \
    hwcodecs \
    "

IMAGE_FEATURES += "${COMMON_FEATURES}" 

inherit extrausers
IMAGE_LINGUAS = " "

IMAGE_INSTALL = "\
		kernel-modules \
		busybox \
		e2fsprogs \
		e2fsprogs-mke2fs \
		e2fsprogs-e2fsck \
		i2c-tools \
		mtd-utils \
		usbutils \
		openssh-sftp-server \
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
		packagegroup-core-ssh-dropbear \
		tcf-agent \
		alsa-plugins \
		adau1761init \
		startup \
                devmem2 \
                libstdc++-dev \
                libstdc++ \
"

EXTRA_USERS_PARAMS = "usermod -P root root;"
