/*
    * RealTime Created By kauantl
    * Created 12 / 03 / 2024
    * Github: https://github.com/kauantltrindade 
    * Version v1.0.1
*/

#if !defined timer_realtime
    #define timer_realtime (1)
#endif

#if !defined negative_realtime
    #define negative_realtime (0)
#endif

new 
    VariableTimer;

// native EnableRealTime ();
// native DisableRealTime ();

public OnGameModeInit ()
{
    print ("\nLoading include: a_realtime.inc\n\n\
       * a_realtime Created By kauantl\n\
       * Created 12 / 03 / 2024\n\
       * Github: https://github.com/kauantltrindade \n\
       * Version v1.0.1\n\n\
       >> a_realtime included v1 (1.0.1)\n\
       Loaded.\n");

    #if defined MyLib_OnGameModeInit
        MyLib_OnGameModeInit ();
    #endif
    return 1;
}

EnableRealTime ()
        return VariableTimer 
                    = SetTimer ("@CheckRealTimer", timer_realtime * 1000, false);

stock DisableRealTime ()
   return KillTimer (VariableTimer);

forward @CheckRealTimer ();
public @CheckRealTimer () {
    static
        hour;

    gettime (hour);

    switch (hour) {
        case 0..4: SetWorldTime (3 - negative_realtime);
        case 5..9: SetWorldTime (7 - negative_realtime);
        case 10..13: SetWorldTime (12 - negative_realtime);
        case 14..17: SetWorldTime (15 - negative_realtime);
        case 18..21: SetWorldTime (1 - negative_realtime);
        case 22..23: SetWorldTime (2 - negative_realtime);
        default: SetWorldTime (15 - negative_realtime);
    }
    VariableTimer 
        = SetTimer ("@CheckRealTimer", timer_realtime * 1000, false);
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#define OnGameModeInit MyLib_OnGameModeInit
#if defined MyLib_OnGameModeInit
    forward MyLib_OnGameModeInit ();
#endif
