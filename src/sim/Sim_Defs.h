#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include<cstdint>
#include<string>
#include <iostream>
#include <fstream>


typedef uint64_t sim_time_type;
typedef uint16_t stream_id_type;
typedef sim_time_type data_timestamp_type;

#define INVALID_TIME 18446744073709551615ULL
#define T0 0
#define INVALID_TIME_STAMP 18446744073709551615ULL
#define MAXIMUM_TIME 18446744073709551615ULL
#define ONE_SECOND 1000000000
typedef std::string sim_object_id_type;

#define CurrentTimeStamp Simulator->Time()
#define PRINT_ERROR(MSG) {\
							std::cerr << "ERROR:" ;\
							std::cerr << MSG << std::endl; \
							std::cin.get();\
							exit(1);\
						 }
#define PRINT_MESSAGE(M) std::cout << M << std::endl;
#define DEBUG2(M) //std::cout<<M<<std::endl;

#define DEBUG_ENABLE 2	// 0 - disabled, 1 - screen, 2 - log file
#define DEBUG_TSTART (0ull)
#define DEBUG_TSTOP (UINT64_MAX)

#if (DEBUG_ENABLE==0)
#  define DEBUG(M)
#  define DEBUG_OPEN
#  define DEBUG_CLOSE
#elif (DEBUG_ENABLE==1)
#  define DEBUG(M) if (CurrentTimeStamp>=DEBUG_TSTART && CurrentTimeStamp<DEBUG_TSTOP) std::cout<<M<<std::endl;
#  define DEBUG_OPEN
#  define DEBUG_CLOSE
#elif (DEBUG_ENABLE==2)
#  define DEBUG(M) if (CurrentTimeStamp>=DEBUG_TSTART && CurrentTimeStamp<DEBUG_TSTOP) cdebug<<M<<std::endl;
#  define DEBUG_OPEN cdebug.open("debug.log");
#  define DEBUG_CLOSE cdebug.close();
#endif


#define SIM_TIME_TO_MICROSECONDS_COEFF 1000
#define SIM_TIME_TO_SECONDS_COEFF 1000000000

extern std::ofstream cdebug;

#endif // !DEFINITIONS_H
