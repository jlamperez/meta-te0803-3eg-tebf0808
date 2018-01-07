
FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += "file://config.cfg \
            file://te0803-3eg-tebf0808.h \
            "
DEPENDS_append_te0803-3eg-tebf0808-zynqmp = " device-tree"

UBOOT_MAKE_TARGET_prepend = " EXT_DTB=${DEPLOY_DIR_IMAGE}/${MACHINE}.dtb "

do_configure_prepend () {

	    install ${WORKDIR}/te0803-3eg-tebf0808.h ${S}/include/configs/

}
