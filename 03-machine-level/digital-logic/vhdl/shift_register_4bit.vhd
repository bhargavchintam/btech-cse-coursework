-- 4-bit right shift register (SISO/SIPO).  ghdl -a shift_register_4bit.vhd shift_register_4bit_tb.vhd && ghdl -e shift_register_4bit_tb && ghdl -r shift_register_4bit_tb
library ieee;
use ieee.std_logic_1164.all;

entity shift_register_4bit is
  port (serial_in, clk, rst : in std_logic;
        q : out std_logic_vector(3 downto 0);
        serial_out : out std_logic);
end shift_register_4bit;

architecture behavioural of shift_register_4bit is
  signal reg : std_logic_vector(3 downto 0) := "0000";
begin
  process (clk, rst)
  begin
    if rst = '1' then
      reg <= "0000";
    elsif rising_edge(clk) then
      reg <= serial_in & reg(3 downto 1);
    end if;
  end process;
  q <= reg;
  serial_out <= reg(0);
end behavioural;
