LIBRARY ieee;
USE ieee.std_logic_1164.all; 
use ieee.numeric_std.all;
entity part2 is
		port(x1: in std_logic;
			  f : out unsigned(0 to 7));
end part2 ;

architecture count of part2 is
signal cnt: integer := 0 ;
begin
process(x1)
begin 
if (x1 = '0') then
	cnt <= (cnt + 1)mod 256;
	f <= to_unsigned(cnt,8);
	--f <= "00100100";
end if;
end process;
	
end count;