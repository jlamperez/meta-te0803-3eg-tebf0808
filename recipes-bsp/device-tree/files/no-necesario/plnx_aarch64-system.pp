# 1 "/home/jlamperez/Proyectos/Trenz_TE0803_and_TE0808/Vivado/2017.4/StarterKit/os/petalinux_jorge/build/../components/plnx_workspace/device-tree/device-tree-generation/system-top.dts"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/home/jlamperez/Proyectos/Trenz_TE0803_and_TE0808/Vivado/2017.4/StarterKit/os/petalinux_jorge/build/../components/plnx_workspace/device-tree/device-tree-generation/system-top.dts"







/dts-v1/;
/include/ "zynqmp.dtsi"
/include/ "zynqmp-clk-ccf.dtsi"
/include/ "pl.dtsi"
/include/ "pcw.dtsi"
/ {
 chosen {
  bootargs = "earlycon clk_ignore_unused";
  stdout-path = "serial0:115200n8";
 };
 aliases {
  ethernet0 = &gem3;
  serial0 = &uart0;
  spi0 = &qspi;
 };
 memory {
  device_type = "memory";
  reg = <0x0 0x0 0x0 0x80000000>;
 };
 cpus {
  /delete-node/ cpu@2 ;
  /delete-node/ cpu@3 ;
 };
};
# 1 "/home/jlamperez/Proyectos/Trenz_TE0803_and_TE0808/Vivado/2017.4/StarterKit/os/petalinux_jorge/build/tmp/work/plnx_aarch64-xilinx-linux/device-tree-generation/xilinx+gitAUTOINC+3c7407f6f8-r0/system-user.dtsi" 1
/include/ "system-conf.dtsi"
/ {
};

&gem3 {
 phy-handle = <&phy0>;
 phy0: phy0@1 {
  device_type = "ethernet-phy";
  reg = <1>;
 };
};

&qspi {
    #address-cells = <1>;
    #size-cells = <0>;
    status = "okay";
    flash0: flash@0 {
        compatible = "n25q256a";
        reg = <0x0>;
        #address-cells = <1>;
        #size-cells = <1>;
    };
};

&i2c0 {
    i2cswitch@73 {
        compatible = "nxp,pca9548";
        #address-cells = <1>;
        #size-cells = <0>;
        reg = <0x73>;
        i2c-mux-idle-disconnect;

        i2c@2 {
            #address-cells = <1>;
            #size-cells = <0>;
            reg = <2>;
        };
        i2c@3 {
            #address-cells = <1>;
            #size-cells = <0>;
            reg = <3>;
        };
        i2c@4 {
            #address-cells = <1>;
            #size-cells = <0>;
            reg = <4>;
        };
        i2c@5 {
            #address-cells = <1>;
            #size-cells = <0>;
            reg = <5>;
        };
        i2c@6 {
            #address-cells = <1>;
            #size-cells = <0>;
            reg = <6>;

            si570_2: clock-generator3@5d {
                #clock-cells = <0>;
                compatible = "silabs,si570";
                reg = <0x5d>;
                temperature-stability = <50>;
                factory-fout = <156250000>;
                clock-frequency = <78800000>;
            };
        };
        i2c@7 {
            #address-cells = <1>;
            #size-cells = <0>;
            reg = <7>;
        };
    };
    i2cswitch@77 {
        compatible = "nxp,pca9548";
        #address-cells = <1>;
        #size-cells = <0>;
        reg = <0x77>;
        i2c-mux-idle-disconnect;
        i2c@0 {
            #address-cells = <1>;
            #size-cells = <0>;
            reg = <0>;
        };
        i2c@1 {
            #address-cells = <1>;
            #size-cells = <0>;
            reg = <1>;






        };
        i2c@2 {
            #address-cells = <1>;
            #size-cells = <0>;
            reg = <2>;
        };
        i2c@3 {
            #address-cells = <1>;
            #size-cells = <0>;
            reg = <3>;
        };
        i2c@4 {
            #address-cells = <1>;
            #size-cells = <0>;
            reg = <4>;
        };
        i2c@5 {
            #address-cells = <1>;
            #size-cells = <0>;
            reg = <5>;
        };
        i2c@6 {
            #address-cells = <1>;
            #size-cells = <0>;
            reg = <6>;
        };
        i2c@7 {
            #address-cells = <1>;
            #size-cells = <0>;
            reg = <7>;
        };
    };
};

&lpd_dma_chan1 {
    status = "disabled";
};
&lpd_dma_chan2 {
    status = "disabled";
};
&lpd_dma_chan3 {
    status = "disabled";
};
&lpd_dma_chan4 {
    status = "disabled";
};
&lpd_dma_chan5 {
    status = "disabled";
};
&lpd_dma_chan6 {
    status = "disabled";
};
&lpd_dma_chan7 {
    status = "disabled";
};
&lpd_dma_chan8 {
    status = "disabled";
};
# 32 "/home/jlamperez/Proyectos/Trenz_TE0803_and_TE0808/Vivado/2017.4/StarterKit/os/petalinux_jorge/build/../components/plnx_workspace/device-tree/device-tree-generation/system-top.dts" 2
