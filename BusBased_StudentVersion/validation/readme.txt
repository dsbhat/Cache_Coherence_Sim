-----------------------------------------------------------------------------------------
[1] Write through

./simulate_cache 32768 8 64 4 0 canneal.04t.debug > write_through_32768_8_64.out
./simulate_cache 32768 8 32 4 0 canneal.04t.debug > write_through_32768_8_32.out
./simulate_cache 65536 8 64 4 0 canneal.04t.longTrace > long_write_through_32768_8_64.out
------------------------------------------------------------------------------------------
[2] Firefly

./simulate_cache 32768 8 64 4 1 canneal.04t.debug > firefly_32768_8_64.out
./simulate_cache 32768 8 32 4 1 canneal.04t.debug > firefly_32768_8_32.out
./simulate_cache 65536 8 64 4 1 canneal.04t.longTrace > long_firefly_32768_8_64.out
------------------------------------------------------------------------------------------
[3] MSI 

./simulate_cache 32768 8 64 4 2 canneal.04t.debug > msi_32768_8_64.out
./simulate_cache 32768 8 32 4 2 canneal.04t.debug > msi_32768_8_32.out
./simulate_cache 65536 8 64 4 2 canneal.04t.longTrace > long_msi_32768_8_64.out
------------------------------------------------------------------------------------------
[4] MSI with upgrade
 
./simulate_cache 32768 8 64 4 3 canneal.04t.debug > msiu_32768_8_64.out
./simulate_cache 32768 8 32 4 3 canneal.04t.debug > msiu_32768_8_32.out
./simulate_cache 65536 8 64 4 3 canneal.04t.longTrace > long_msiu_32768_8_64.out

-----------------------------------GOOD LUCK-----------------------------------------------