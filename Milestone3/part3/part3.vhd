LIBRARY ieee;
USE ieee.std_logic_1164.all; 
use ieee.numeric_std.all;
entity part3 is
		port(x1: in std_logic;
			  f0 : out unsigned(0 to 6);
			  f1 : out unsigned(0 to 6));
			  
end part3 ;

architecture count of part3 is
signal cnt: integer := 0 ;
begin

process(x1)
variable lsd, msd: integer :=0;

begin 
if (x1 = '0') then
	cnt <= (cnt + 1)mod 100;
	msd := cnt/10;
	lsd := cnt mod 10;
	
	case msd is
		when 0 => f0 <= "0000001";
		when 1 => f0 <= "1001111";
		when 2 => f0 <= "0010010";
		when 3 => f0 <= "0000110";
		when 4 => f0 <= "1001100";
		when 5 => f0 <= "0100100";
		when 6 => f0 <= "0100000";
		when 7 => f0 <= "0001111";
		when 8 => f0 <= "0000000";
		when 9 => f0 <= "0001100";
		when others => report "unreachable" severity failure;
	end case;	
		
	case lsd is
		when 0 => f1 <= "0000001";
		when 1 => f1 <= "1001111";
		when 2 => f1 <= "0010010";
		when 3 => f1 <= "0000110";
		when 4 => f1 <= "1001100";
		when 5 => f1 <= "0100100";
		when 6 => f1 <= "0100000";
		when 7 => f1 <= "0001111";
		when 8 => f1 <= "0000000";
		when 9 => f1 <= "0001100";
		when others => report "unreachable" severity failure;
	end case;	
		
	
	
end if;
end process;
	
end count;