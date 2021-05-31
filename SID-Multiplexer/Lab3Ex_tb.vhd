--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   23:47:58 04/12/2021
-- Design Name:   
-- Module Name:   C:/Data/Xilinx/Lab3Ex/Lab3Ex_tb.vhd
-- Project Name:  Lab3
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: lab3
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY Lab3Ex_tb IS
END Lab3Ex_tb;
 
ARCHITECTURE behavior OF Lab3Ex_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT lab3
    PORT(
         SW0 : IN  std_logic;
         SW1 : IN  std_logic;
         SW2 : IN  std_logic;
         SW3 : IN  std_logic;
         digit : OUT  std_logic_vector(3 downto 0);
         seg : OUT  std_logic_vector(6 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal SW0 : std_logic := '0';
   signal SW1 : std_logic := '0';
   signal SW2 : std_logic := '0';
   signal SW3 : std_logic := '0';

 	--Outputs
   signal digit : std_logic_vector(3 downto 0);
   signal seg : std_logic_vector(6 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   constant SW0_period : time := 800 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: lab3 PORT MAP (
          SW0 => SW0,
          SW1 => SW1,
          SW2 => SW2,
          SW3 => SW3,
          digit => digit,
          seg => seg
        );

   -- Clock process definitions
   SW0_process :process
   begin
		SW0 <= '1';
		wait for SW0_period;
   end process;
	
	SW1_process :process
	begin
		SW1 <= '1';
		wait for SW0_period/4;
		SW1 <= '0';
		wait for SW0_period/4;
		SW1 <= '1';
		wait for SW0_period/2;
	end process;
	
	SW2_process :process
	begin
		SW2 <= '1';
		wait for SW0_period/2;
		SW2 <= '0';
		wait for SW0_period/4;
		SW2 <= '1';
		wait for SW0_period/4;
	end process;
		
	SW3_process :process
	begin
		SW3 <= '1';
		wait for SW0_period*3/4;
		SW3 <= '0';
		wait for SW0_period/4;
	end process;


   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for SW0_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
