-- 4-bit ripple carry adder, structural (four full_adder instances)
-- ghdl -a full_adder.vhd ripple_adder_4bit.vhd ripple_adder_4bit_tb.vhd && ghdl -e ripple_adder_4bit_tb && ghdl -r ripple_adder_4bit_tb
library ieee;
use ieee.std_logic_1164.all;

entity ripple_adder_4bit is
  port (a, b : in std_logic_vector(3 downto 0);
        cin  : in std_logic;
        sum  : out std_logic_vector(3 downto 0);
        cout : out std_logic);
end ripple_adder_4bit;

architecture structural of ripple_adder_4bit is
  component full_adder
    port (a, b, cin : in std_logic; sum, cout : out std_logic);
  end component;
  signal c : std_logic_vector(4 downto 0);
begin
  c(0) <= cin;
  gen : for i in 0 to 3 generate
    fa : full_adder port map (a(i), b(i), c(i), sum(i), c(i+1));
  end generate;
  cout <= c(4);
end structural;
