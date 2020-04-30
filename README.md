## *Taz 5 Aerostruder thermistor hotfix*

Quickly patched 2016 Q2 "Uaru" firmware for Lulz Taz 5 + Aerostruder to use a standard 100k EPCOS thermistor instead of the sheathed Semitec provided by E3D.   

This Lulzbot Marlin source is more than 4 years old, these patches just get the machine running again ASAP.

upload to the printer with ```arduino --upload Marlin/*.ino```  



#### *Changes:*

- Fix struct conflict in ```stdio.h``` with Marlin SD reader files at ```/hardware/tools/avr/avr/include/stdio.h```
  - *This was later fixed with [this Marlin PR](https://github.com/MarlinFirmware/Marlin/pull/5114/commits/8906c93ce54be7a40aff2259c62154337e15c332)*


- Fix ```u8g.h``` locations in ```dogm_font_data_marlin.h```

- *Some other relevant diffs:*

```
< #define TEMP_SENSOR_0 1  // Jess: using standard, unsheathed EPCOS instead of sheathed semitec
---
> #define TEMP_SENSOR_0 5
135d132

// Jess: residency should be lazier than standard
137c134
< #define TEMP_RESIDENCY_TIME 0.6  // (seconds)
---
> #define TEMP_RESIDENCY_TIME 0.5  // (seconds)
327,336c324,329

< // JessS: modified for Marlin_TAZ config
< #define INVERT_X_DIR false
< #define INVERT_Y_DIR true
< #define INVERT_Z_DIR false
< #define INVERT_E0_DIR true
< #define INVERT_E1_DIR true
< #define INVERT_E2_DIR false
< #define INVERT_E3_DIR false
< #define INVERT_E4_DIR false
< #define INVERT_E5_DIR false
---
> #define INVERT_X_DIR false    // for Mendel set to false, for Orca set to true
> #define INVERT_Y_DIR true    // for Mendel set to true, for Orca set to false
> #define INVERT_Z_DIR false     // for Mendel set to false, for Orca set to true
> #define INVERT_E0_DIR true   // for direct drive extruder v9 set to true, for geared extruder set to false
> #define INVERT_E1_DIR true    // for direct drive extruder v9 set to true, for geared extruder set to false
> #define INVERT_E2_DIR true   // for direct drive extruder v9 set to true, for geared extruder set to false

diff Marlin/dogm_font_data_marlin.h diffs/Marlin/dogm_font_data_marlin.h
< #include <clib/u8g.h>
---
> #include <utility/u8g.h>
171c171
< #include <clib/u8g.h>
---
> #include <utility/u8g.h>
337a338
>
```
