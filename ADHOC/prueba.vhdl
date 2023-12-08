LIBRARY ieee;
USE ieee.STD_LOGIC_1164.all;

ENTITY FSM_ascensor IS
PORT (clk: IN STD_LOGIC; -- activo por flanco de subida
codigo_piso: IN STD_LOGIC_VECTOR (1 DOWNTO 0); --código binario del Nº de piso
-- pulsado
sube, baja: OUT STD_LOGIC; -- sentido del movimiento
piso_donde_esta: OUT STD_LOGIC_VECTOR (1 DOWNTO 0)); -- código binario del
--piso donde se encuentra que coincide con el código asignado a la luz del panel
END FSM_ascensor;

architecture FSM_arquitectura of FSM_ascensor is
    
    type tipo_estados is (piso_0,piso_1,piso_2); -- - enumeration of variables preprogrammed by the programmer xd :D

    signal e_actual : tipo_estados;
    signal e_futuro : tipo_estados;

    begin
        process(clk,codigo_piso)
        begin
            if rising_edge(clk) then
                e_actual <= piso_0;
                if(piso_donde_esta = "00") then
                    e_actual <= piso_0; 
                    case codigo_piso is
                        when "00" => sube <= '0'; baja <= '0';e_futuro<=piso_0;piso_donde_esta<="00";
                        when "01" => sube <= '1'; baja  <='0';e_futuro<=piso_1;piso_donde_esta<="01";
                        when "10" => sube <= '1'; baja <= '0';e_futuro<=piso_2;piso_donde_esta<="10";
                        when others => sube <= '0'; baja <= '0';e_futuro<=piso_0;piso_donde_esta<="00";
                    end case;
                end if;

                if(piso_donde_esta = "01") then
                    e_actual <= piso_1;
                    case codigo_piso is
                        when "00" => sube <= '0'; baja <= '1';e_futuro<=piso_0;piso_donde_esta<="00";
                        when "01" => sube <= '0'; baja <= '0';e_futuro<=piso_1;piso_donde_esta<="01";
                        when "10" => sube <= '1'; baja <= '0';e_futuro<=piso_2;piso_donde_esta<="10";
                        when others => sube <= '0'; baja  <='0';e_futuro<=piso_1;piso_donde_esta<="01";
                    end case;
                end if;

                if(piso_donde_esta = "10") then
                    e_actual <= piso_2;
                    case codigo_piso is
                        when "00" => sube <= '0'; baja <= '1';e_futuro<=piso_0;piso_donde_esta<="00";
                        when "01" => sube <= '0'; baja <= '1';e_futuro<=piso_1;piso_donde_esta<="01";
                        when "10" => sube <= '0'; baja <= '0';e_futuro<=piso_2;piso_donde_esta<="10";
                        when others  => sube <= '0'; baja  <='0';e_futuro<=piso_2;piso_donde_esta<="10";
                    end case;
                end if;
            end if;
        end process;

end FSM_arquitectura;

library ieee;
use ieee.std_logic_1164.all;

entity ascensor_completo is
    PORT (
        clk : in std_logic;
        piso_donde_va:in std_logic_vector(2 downto 0);
        codigo_piso_input : in std_logic_vector(1 downto 0);
        codigo_piso:out std_logic_vector(1 downto 0);
        baja            : OUT   STD_LOGIC;
        sube            : out std_logic;
        piso_donde_esta     : OUT STD_LOGIC_VECTOR(1 DOWNTO 0)
    );
end ascensor_completo;

architecture arquitectura_ascensor_completo of ascensor_completo is
    component codifica_boton is
        port(
            piso_donde_va       : IN    STD_LOGIC_VECTOR (2 DOWNTO 0);
            codigo_piso         : out std_logic_vector(1 downto 0)
        );
    end component;

    component FSM_ascensor is
        port(
                    clk               : in std_logic;
                    --codigo_piso           : IN    STD_LOGIC_VECTOR(1 DOWNTO 0);
                    codigo_piso         : in std_logic_vector(1 downto 0);
                    sube            : out std_logic;
                    baja            : OUT   STD_LOGIC;
                    piso_donde_esta     : OUT STD_LOGIC_VECTOR(1 DOWNTO 0)
        );
    end component;

    --signal piso_donde_va          :  STD_LOGIC_VECTOR (2 DOWNTO 0);       -- boton que se activa
    --signal codigo_piso        :  STD_LOGIC_VECTOR(1 DOWNTO 0);            -- codigo generado

begin
    u1: codifica_boton port map( piso_donde_va => piso_donde_va, codigo_piso => codigo_piso);
    u2: FSM_ascensor port map(clk => clk, codigo_piso => codigo_piso_input, sube => sube, baja => baja, piso_donde_esta => piso_donde_esta);
end arquitectura_ascensor_completo;



-- EL TEST

library ieee;
use ieee.std_logic_1164.all;

entity ascensor_completo_test is
end ascensor_completo_test;

architecture arquitectura_ascensor_completo_test of ascensor_completo_test is

    component ascensor_completo is
        --3 inputs, 4 outputs
        port(
            clk               : IN std_logic;
            piso_donde_va       : IN    STD_LOGIC_VECTOR (2 DOWNTO 0); -- selecci�n de piso 
            codigo_piso_input   : IN std_logic_vector(1 downto 0);

            codigo_piso         : OUT STD_LOGIC_VECTOR (1 DOWNTO 0);    -- codigo generado
            sube            : OUT std_logic;
            baja            : OUT   STD_LOGIC;
            piso_donde_esta     : OUT STD_LOGIC_VECTOR(1 DOWNTO 0)
        );
    end component;

    constant periodo            :  TIME := 20 ns;
    signal reloj                :  STD_LOGIC := '0';                -- Arranque de secuencia del reloj
    signal piso_donde_va        :  STD_LOGIC_VECTOR (2 DOWNTO 0);       
    signal codigo_piso      :  STD_LOGIC_VECTOR(1 DOWNTO 0);            
    signal codigo_piso_input        :  STD_LOGIC_VECTOR(1 DOWNTO 0);   
    signal sube            :    STD_LOGIC;
    signal baja         :   STD_LOGIC;
    signal piso_donde_esta      :  STD_LOGIC_VECTOR(1 DOWNTO 0);

begin
    ascen: ascensor_completo PORT MAP (
                piso_donde_va   => piso_donde_va,           -- boton que es activado    
                codigo_piso     => codigo_piso,             -- codigo generado   
                codigo_piso_input       => codigo_piso_input,
                clk => reloj,
                sube => sube,
                baja => baja,
                piso_donde_esta => piso_donde_esta
    ); 

    reloj   <= NOT reloj AFTER periodo/2;

piso_donde_va <= "100",                             -- piso 2
    "001" AFTER periodo,            -- piso 0
    "010" AFTER 2 * periodo,        -- piso 1
    "100" AFTER 3 * periodo,        -- piso 2
    "000" AFTER 4 * periodo,            -- sin marcar piso
    "111" AFTER 5 * periodo,            -- se aprietan tres botones a la vez
    "001" AFTER 6 * periodo,            -- piso 0
"100" AFTER 7 * periodo,            -- piso 2
"010" AFTER 8 * periodo,            -- piso 1
"100" AFTER 9 * periodo,            -- piso 2
"001" AFTER 10 * periodo;           -- piso 0

codigo_piso_input            <= "10",                     -- piso 2
                "00" AFTER periodo,         -- piso 0
                "01" AFTER 2 * periodo,     -- piso 1
                "10" AFTER 3 * periodo,     -- piso 2
                "11" AFTER 4 * periodo,     -- sin marcar piso
                "11" AFTER 5 * periodo,     -- se aprietan dos botones a la vez
                "01" AFTER 6 * periodo,     -- piso 0
            "10" AFTER 7 * periodo,     -- piso 2
            "01" AFTER 8 * periodo,     -- piso 1
            "10" AFTER 9 * periodo,     -- piso 2
            "01" AFTER 10 * periodo;        -- piso 0

end arquitectura_ascensor_completo_test;