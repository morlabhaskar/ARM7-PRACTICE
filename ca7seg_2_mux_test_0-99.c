#include "seg.h"
#include "types.h"

main()
{
    u32 i, dly;
    init_2_mux_segs();
    while (1){
        for (i = 0; i < 100; i++){
            for (dly = 100; dly > 0; dly--){
                disp_2_mux_segs(i);
            }
        }
    }
}
