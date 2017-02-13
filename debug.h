//
// Created by omni on 17-2-10.
//

#ifndef DEBUG_DEBUG_H
#define DEBUG_DEBUG_H

#define DRV_DEBUG 1
#define DRV_DEBUG_IN 0x0001
#define DRV_DEBUG_OUT 0x0002
#define DRV_DEBUG_ERR 0x0003
#define DRV_DEBUG_ALL 0x0004

#if DRV_DEBUG
#define DRV_PRINT(flag, fmt, args...) \
            do{\
                switch (flag) \
                { \
                    case DRV_DEBUG_IN: \
                        printf("\e[1;35m[%s:%d]%s\e[0m"#fmt"\n", __FILE__, __LINE__, __FUNCTION__,##args);\
                        break; \
                    case DRV_DEBUG_OUT: \
                    case DRV_DEBUG_ALL: \
                          printf("\e[1;36m[%s:%d]%s\e[0m"#fmt"\n", __FILE__, __LINE__, __FUNCTION__,##args);\
                        break; \
                    case DRV_DEBUG_ERR: \
                           printf("\e[1;39m[%s:%d]%s\e[0m"#fmt"\n", __FILE__, __LINE__, __FUNCTION__,##args);\
                    default: \
                        printf("\e[1;33m[%s:%d]%s\e[0m"#fmt"\n", __FILE__, __LINE__, __FUNCTION__,##args);\
                        break; \
                }\
            }while(0)
#else
#define DRV_PRINT(fmt, ...)
#endif





#endif //DEBUG_DEBUG_H
