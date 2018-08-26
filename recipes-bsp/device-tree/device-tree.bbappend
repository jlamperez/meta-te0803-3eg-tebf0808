FILESEXTRAPATHS_prepend_te0803-3eg-tebf0808-zynqmp := "${THISDIR}/files/te0803-3eg-tebf0808-zynqmp:"

COMPATIBLE_MACHINE_te0803-3eg-tebf0808-zynqmp = ".*"
SRC_URI_append_te0803-3eg-tebf0808-zynqmp += " \
                               file://pcw.dtsi \
                               file://pl.dtsi \
                               file://te0803-3eg-tebf0808-zynqmp.dts \
                               file://zynqmp-clk-ccf.dtsi \
                               file://zynqmp.dtsi \
                               "
