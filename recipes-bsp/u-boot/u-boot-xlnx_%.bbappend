
FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += "file://config.cfg \
            file://te0803-3eg-tebf0808.h \
            "
UBOOT_MAKE_TARGET_append = " EXT_DTB=${DEPLOY_DIR_IMAGE}/${MACHINE}-system.dtb"

do_configure_append () {
	install ${WORKDIR}/te0803-3eg-tebf0808.h ${S}/include/configs/
}
