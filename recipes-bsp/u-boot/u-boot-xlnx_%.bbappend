
FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI_append = "file://defconfig \
            file://te0803-3eg-tebf0808.h \
"
DEPENDS_append_te0803-3eg-tebf0808-zynqmp = " device-tree"

UBOOT_MAKE_TARGET_append = " EXT_DTB=${DEPLOY_DIR_IMAGE}/${MACHINE}.dtb "

do_configure_append () {

	    install ${WORKDIR}/te0803-3eg-tebf0808.h ${S}/include/configs/
            install ${WORKDIR}/defconfig ${S}/configs/${MACHINE}_defconfig
}

do_compile_prepend () {
            mkdir -p ${B}/arch/arm/dts/
            cp ${DEPLOY_DIR_IMAGE}/${MACHINE}.dtb ${B}/arch/arm/dts/
}
