-- Copyright (C) 1991-2015 Altera Corporation. All rights reserved.
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, the Altera Quartus II License Agreement,
-- the Altera MegaCore Function License Agreement, or other 
-- applicable license agreement, including, without limitation, 
-- that your use is for the sole purpose of programming logic 
-- devices manufactured by Altera and sold by Altera or its 
-- authorized distributors.  Please refer to the applicable 
-- agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 15.0.0 Build 145 04/22/2015 SJ Web Edition"

-- DATE "02/27/2017 13:31:07"

-- 
-- Device: Altera EP4CE115F29C7 Package FBGA780
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA;
LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	part2 IS
    PORT (
	x1 : IN std_logic;
	f : BUFFER std_logic_vector(0 TO 7)
	);
END part2;

-- Design Ports Information
-- f[7]	=>  Location: PIN_J15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- f[6]	=>  Location: PIN_H16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- f[5]	=>  Location: PIN_J16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- f[4]	=>  Location: PIN_H17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- f[3]	=>  Location: PIN_F15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- f[2]	=>  Location: PIN_G15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- f[1]	=>  Location: PIN_G16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- f[0]	=>  Location: PIN_H15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x1	=>  Location: PIN_M21,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF part2 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_x1 : std_logic;
SIGNAL ww_f : std_logic_vector(0 TO 7);
SIGNAL \f[7]~output_o\ : std_logic;
SIGNAL \f[6]~output_o\ : std_logic;
SIGNAL \f[5]~output_o\ : std_logic;
SIGNAL \f[4]~output_o\ : std_logic;
SIGNAL \f[3]~output_o\ : std_logic;
SIGNAL \f[2]~output_o\ : std_logic;
SIGNAL \f[1]~output_o\ : std_logic;
SIGNAL \f[0]~output_o\ : std_logic;
SIGNAL \x1~input_o\ : std_logic;
SIGNAL \cnt[0]~21_combout\ : std_logic;
SIGNAL \f[7]~reg0feeder_combout\ : std_logic;
SIGNAL \f[7]~reg0_q\ : std_logic;
SIGNAL \cnt[1]~7_combout\ : std_logic;
SIGNAL \f[6]~reg0feeder_combout\ : std_logic;
SIGNAL \f[6]~reg0_q\ : std_logic;
SIGNAL \cnt[1]~8\ : std_logic;
SIGNAL \cnt[2]~9_combout\ : std_logic;
SIGNAL \f[5]~reg0feeder_combout\ : std_logic;
SIGNAL \f[5]~reg0_q\ : std_logic;
SIGNAL \cnt[2]~10\ : std_logic;
SIGNAL \cnt[3]~11_combout\ : std_logic;
SIGNAL \f[4]~reg0feeder_combout\ : std_logic;
SIGNAL \f[4]~reg0_q\ : std_logic;
SIGNAL \cnt[3]~12\ : std_logic;
SIGNAL \cnt[4]~13_combout\ : std_logic;
SIGNAL \f[3]~reg0feeder_combout\ : std_logic;
SIGNAL \f[3]~reg0_q\ : std_logic;
SIGNAL \cnt[4]~14\ : std_logic;
SIGNAL \cnt[5]~15_combout\ : std_logic;
SIGNAL \f[2]~reg0feeder_combout\ : std_logic;
SIGNAL \f[2]~reg0_q\ : std_logic;
SIGNAL \cnt[5]~16\ : std_logic;
SIGNAL \cnt[6]~17_combout\ : std_logic;
SIGNAL \f[1]~reg0feeder_combout\ : std_logic;
SIGNAL \f[1]~reg0_q\ : std_logic;
SIGNAL \cnt[6]~18\ : std_logic;
SIGNAL \cnt[7]~19_combout\ : std_logic;
SIGNAL \f[0]~reg0feeder_combout\ : std_logic;
SIGNAL \f[0]~reg0_q\ : std_logic;
SIGNAL cnt : std_logic_vector(31 DOWNTO 0);
SIGNAL \ALT_INV_x1~input_o\ : std_logic;

BEGIN

ww_x1 <= x1;
f <= ww_f;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_x1~input_o\ <= NOT \x1~input_o\;

-- Location: IOOBUF_X60_Y73_N23
\f[7]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \f[7]~reg0_q\,
	devoe => ww_devoe,
	o => \f[7]~output_o\);

-- Location: IOOBUF_X65_Y73_N23
\f[6]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \f[6]~reg0_q\,
	devoe => ww_devoe,
	o => \f[6]~output_o\);

-- Location: IOOBUF_X65_Y73_N16
\f[5]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \f[5]~reg0_q\,
	devoe => ww_devoe,
	o => \f[5]~output_o\);

-- Location: IOOBUF_X67_Y73_N9
\f[4]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \f[4]~reg0_q\,
	devoe => ww_devoe,
	o => \f[4]~output_o\);

-- Location: IOOBUF_X58_Y73_N2
\f[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \f[3]~reg0_q\,
	devoe => ww_devoe,
	o => \f[3]~output_o\);

-- Location: IOOBUF_X65_Y73_N9
\f[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \f[2]~reg0_q\,
	devoe => ww_devoe,
	o => \f[2]~output_o\);

-- Location: IOOBUF_X67_Y73_N2
\f[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \f[1]~reg0_q\,
	devoe => ww_devoe,
	o => \f[1]~output_o\);

-- Location: IOOBUF_X60_Y73_N16
\f[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \f[0]~reg0_q\,
	devoe => ww_devoe,
	o => \f[0]~output_o\);

-- Location: IOIBUF_X115_Y53_N15
\x1~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x1,
	o => \x1~input_o\);

-- Location: LCCOMB_X65_Y69_N6
\cnt[0]~21\ : cycloneive_lcell_comb
-- Equation(s):
-- \cnt[0]~21_combout\ = !cnt(0)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => cnt(0),
	combout => \cnt[0]~21_combout\);

-- Location: FF_X65_Y69_N7
\cnt[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_x1~input_o\,
	d => \cnt[0]~21_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => cnt(0));

-- Location: LCCOMB_X65_Y69_N0
\f[7]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \f[7]~reg0feeder_combout\ = cnt(0)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => cnt(0),
	combout => \f[7]~reg0feeder_combout\);

-- Location: FF_X65_Y69_N1
\f[7]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_x1~input_o\,
	d => \f[7]~reg0feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \f[7]~reg0_q\);

-- Location: LCCOMB_X65_Y69_N16
\cnt[1]~7\ : cycloneive_lcell_comb
-- Equation(s):
-- \cnt[1]~7_combout\ = (cnt(0) & (cnt(1) $ (VCC))) # (!cnt(0) & (cnt(1) & VCC))
-- \cnt[1]~8\ = CARRY((cnt(0) & cnt(1)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110011010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => cnt(0),
	datab => cnt(1),
	datad => VCC,
	combout => \cnt[1]~7_combout\,
	cout => \cnt[1]~8\);

-- Location: FF_X65_Y69_N17
\cnt[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_x1~input_o\,
	d => \cnt[1]~7_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => cnt(1));

-- Location: LCCOMB_X65_Y69_N2
\f[6]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \f[6]~reg0feeder_combout\ = cnt(1)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => cnt(1),
	combout => \f[6]~reg0feeder_combout\);

-- Location: FF_X65_Y69_N3
\f[6]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_x1~input_o\,
	d => \f[6]~reg0feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \f[6]~reg0_q\);

-- Location: LCCOMB_X65_Y69_N18
\cnt[2]~9\ : cycloneive_lcell_comb
-- Equation(s):
-- \cnt[2]~9_combout\ = (cnt(2) & (!\cnt[1]~8\)) # (!cnt(2) & ((\cnt[1]~8\) # (GND)))
-- \cnt[2]~10\ = CARRY((!\cnt[1]~8\) # (!cnt(2)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => cnt(2),
	datad => VCC,
	cin => \cnt[1]~8\,
	combout => \cnt[2]~9_combout\,
	cout => \cnt[2]~10\);

-- Location: FF_X65_Y69_N19
\cnt[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_x1~input_o\,
	d => \cnt[2]~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => cnt(2));

-- Location: LCCOMB_X65_Y69_N4
\f[5]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \f[5]~reg0feeder_combout\ = cnt(2)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => cnt(2),
	combout => \f[5]~reg0feeder_combout\);

-- Location: FF_X65_Y69_N5
\f[5]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_x1~input_o\,
	d => \f[5]~reg0feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \f[5]~reg0_q\);

-- Location: LCCOMB_X65_Y69_N20
\cnt[3]~11\ : cycloneive_lcell_comb
-- Equation(s):
-- \cnt[3]~11_combout\ = (cnt(3) & (\cnt[2]~10\ $ (GND))) # (!cnt(3) & (!\cnt[2]~10\ & VCC))
-- \cnt[3]~12\ = CARRY((cnt(3) & !\cnt[2]~10\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => cnt(3),
	datad => VCC,
	cin => \cnt[2]~10\,
	combout => \cnt[3]~11_combout\,
	cout => \cnt[3]~12\);

-- Location: FF_X65_Y69_N21
\cnt[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_x1~input_o\,
	d => \cnt[3]~11_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => cnt(3));

-- Location: LCCOMB_X65_Y69_N14
\f[4]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \f[4]~reg0feeder_combout\ = cnt(3)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => cnt(3),
	combout => \f[4]~reg0feeder_combout\);

-- Location: FF_X65_Y69_N15
\f[4]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_x1~input_o\,
	d => \f[4]~reg0feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \f[4]~reg0_q\);

-- Location: LCCOMB_X65_Y69_N22
\cnt[4]~13\ : cycloneive_lcell_comb
-- Equation(s):
-- \cnt[4]~13_combout\ = (cnt(4) & (!\cnt[3]~12\)) # (!cnt(4) & ((\cnt[3]~12\) # (GND)))
-- \cnt[4]~14\ = CARRY((!\cnt[3]~12\) # (!cnt(4)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => cnt(4),
	datad => VCC,
	cin => \cnt[3]~12\,
	combout => \cnt[4]~13_combout\,
	cout => \cnt[4]~14\);

-- Location: FF_X65_Y69_N23
\cnt[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_x1~input_o\,
	d => \cnt[4]~13_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => cnt(4));

-- Location: LCCOMB_X65_Y69_N12
\f[3]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \f[3]~reg0feeder_combout\ = cnt(4)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => cnt(4),
	combout => \f[3]~reg0feeder_combout\);

-- Location: FF_X65_Y69_N13
\f[3]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_x1~input_o\,
	d => \f[3]~reg0feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \f[3]~reg0_q\);

-- Location: LCCOMB_X65_Y69_N24
\cnt[5]~15\ : cycloneive_lcell_comb
-- Equation(s):
-- \cnt[5]~15_combout\ = (cnt(5) & (\cnt[4]~14\ $ (GND))) # (!cnt(5) & (!\cnt[4]~14\ & VCC))
-- \cnt[5]~16\ = CARRY((cnt(5) & !\cnt[4]~14\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => cnt(5),
	datad => VCC,
	cin => \cnt[4]~14\,
	combout => \cnt[5]~15_combout\,
	cout => \cnt[5]~16\);

-- Location: FF_X65_Y69_N25
\cnt[5]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_x1~input_o\,
	d => \cnt[5]~15_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => cnt(5));

-- Location: LCCOMB_X65_Y69_N10
\f[2]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \f[2]~reg0feeder_combout\ = cnt(5)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => cnt(5),
	combout => \f[2]~reg0feeder_combout\);

-- Location: FF_X65_Y69_N11
\f[2]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_x1~input_o\,
	d => \f[2]~reg0feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \f[2]~reg0_q\);

-- Location: LCCOMB_X65_Y69_N26
\cnt[6]~17\ : cycloneive_lcell_comb
-- Equation(s):
-- \cnt[6]~17_combout\ = (cnt(6) & (!\cnt[5]~16\)) # (!cnt(6) & ((\cnt[5]~16\) # (GND)))
-- \cnt[6]~18\ = CARRY((!\cnt[5]~16\) # (!cnt(6)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => cnt(6),
	datad => VCC,
	cin => \cnt[5]~16\,
	combout => \cnt[6]~17_combout\,
	cout => \cnt[6]~18\);

-- Location: FF_X65_Y69_N27
\cnt[6]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_x1~input_o\,
	d => \cnt[6]~17_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => cnt(6));

-- Location: LCCOMB_X65_Y69_N8
\f[1]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \f[1]~reg0feeder_combout\ = cnt(6)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => cnt(6),
	combout => \f[1]~reg0feeder_combout\);

-- Location: FF_X65_Y69_N9
\f[1]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_x1~input_o\,
	d => \f[1]~reg0feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \f[1]~reg0_q\);

-- Location: LCCOMB_X65_Y69_N28
\cnt[7]~19\ : cycloneive_lcell_comb
-- Equation(s):
-- \cnt[7]~19_combout\ = \cnt[6]~18\ $ (!cnt(7))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000001111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datad => cnt(7),
	cin => \cnt[6]~18\,
	combout => \cnt[7]~19_combout\);

-- Location: FF_X65_Y69_N29
\cnt[7]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_x1~input_o\,
	d => \cnt[7]~19_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => cnt(7));

-- Location: LCCOMB_X65_Y69_N30
\f[0]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \f[0]~reg0feeder_combout\ = cnt(7)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => cnt(7),
	combout => \f[0]~reg0feeder_combout\);

-- Location: FF_X65_Y69_N31
\f[0]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_x1~input_o\,
	d => \f[0]~reg0feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \f[0]~reg0_q\);

ww_f(7) <= \f[7]~output_o\;

ww_f(6) <= \f[6]~output_o\;

ww_f(5) <= \f[5]~output_o\;

ww_f(4) <= \f[4]~output_o\;

ww_f(3) <= \f[3]~output_o\;

ww_f(2) <= \f[2]~output_o\;

ww_f(1) <= \f[1]~output_o\;

ww_f(0) <= \f[0]~output_o\;
END structure;


