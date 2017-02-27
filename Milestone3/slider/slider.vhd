LIBRARY ieee;
USE ieee.std_logic_1164.all;
entity slider is
		port(x1,x2: in std_logic;
				f	 : out std_logic);
end slider;

architecture andGate of slider is
begin 
	f<= x1 and x2;
end andGate;