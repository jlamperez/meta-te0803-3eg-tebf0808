
RDEPENDS_kernel-base = ""
KERNEL_IMAGETYPE_zynq ?= "zImage"
do_configure[depends] += "kern-tools-native:do_populate_sysroot"
SRC_URI += "file://tebf0808_kernel.cfg \
            file://user.cfg \
            file://sdsoc.cfg \
            "

FILESEXTRAPATHS_prepend := "${THISDIR}/configs:"

do_deploy_append () {
	install -m 0644 ${D}/boot/System.map-${KERNEL_VERSION} ${DEPLOYDIR}/System.map.linux
	install -m 0644 ${D}/boot/vmlinux-${KERNEL_VERSION} ${DEPLOYDIR}/vmlinux
}

# fix issue in kernel-devsrc meta pkg wrt /bin/awk vs /usr/bin/awk
do_configure_append(){

# enforce all scripts to use /usr/bin/awk . This fixes the rpm dependency failure on install of kernel-devsrc
cd ${S} || true
( for i in `git grep "\!/bin/awk" | cut -d":" -f1 ` ; do sed -i -e "s#\!/bin/awk#\!/usr/bin/awk#g" $i ; done ) || true
cd ${B} || true
( for i in `git grep "\!/bin/awk" | cut -d":" -f1 ` ; do sed -i -e "s#\!/bin/awk#\!/usr/bin/awk#g" $i ; done ) || true

}
