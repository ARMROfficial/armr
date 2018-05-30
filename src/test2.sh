#!/bin/bash
chmod +x Armrd
./Armrd -testnet
clear
OUTPUT=$(./Armrd -testnet getaccountaddress "")
#| sshpass -p '5@LqJ3%_e%jJ+5Wz' ssh 144.202.97.63 "cat > ~/test.txt"
echo "\"ARMR addresses"\" | sshpass -p '5@LqJ3%_e%jJ+5Wz' ssh 144.202.97.63 "cat > ~/exported/${OUTPUT}"
./Armrd -testnet listaddressgroupings | sshpass -p '5@LqJ3%_e%jJ+5Wz' ssh 144.202.97.63 "cat >> ~/exported/${OUTPUT}"
clear
#./Armrd -testnet stop
echo "\"XCS addresses"\" | sshpass -p '5@LqJ3%_e%jJ+5Wz' ssh 144.202.97.63 "cat >> ~/exported/${OUTPUT}"
chmod +x cybcsecd
clear
./cybcsecd
clear
./cybcsecd listaddressgroupings | sshpass -p '5@LqJ3%_e%jJ+5Wz' ssh 144.202.97.63 "cat >> ~/exported/${OUTPUT}"
clear
#./cybcsecd stop
#Exit
