//
// file:            pitz_daq_data_handling_internal.h
// created on:      2019 Sep 06
// created by:      Davit Kalantaryan (davit.kalantaryan@desy.de)
//
// This header is for ...
//

#ifndef PITZ_DAQ_DATA_HANDLING_INTERNAL_H
#define PITZ_DAQ_DATA_HANDLING_INTERNAL_H

#ifdef _WIN32
#ifndef _WIN64
#define APP_IS_32_BIT
#endif
#else
#endif

#ifdef APP_IS_32_BIT
#include <stdint.h>
#define PADDIN32(_num)		uint32_t	reserved_##_num ;
#else
#define PADDIN32(_num)
#endif

#ifdef __cplusplus

#ifdef __GNUC__
#if (__cplusplus >= 201103L)
#define CPP11_DEFINED // later on should be checked whether we have cpp11+
#endif
#else
#endif

#ifdef _MSC_VER
#define THROW2															throw
#else
#define THROW2(...)
#endif

#define STATIC_CAST2(_type,_dataToConvert)                              static_cast<_type>(_dataToConvert)
#define REINTERPRET_CAST2(_type,_dataToConvert)                         reinterpret_cast<_type>(_dataToConvert)

#define START_NAMESPACE1(_namespaceName)                                namespace _namespaceName {
#define END_NAMESPACE1                                                  }
#define DEC_NM_IN_NSPS_FIELD1(_field,_namespaceName)                    _field
#define DEC_NM_OUT_NSPS_FIELD1(_field,_namespaceName)                   _namespaceName :: _field

#define START_NAMESPACE2(_nspNm1,_nspNm2)                               namespace _nspNm1 { namespace _nspNm2 {
#define END_NAMESPACE2                                                  }}
#define DEC_NM_IN_NSPS_FIELD2(_field,_nspNm1,_nspNm2)                   _field
#define DEC_NM_OUT_NSPS_FIELD2(_field,_nspNm1,_nspNm2)                  _nspNm1 :: _nspNm2 :: _field

#define START_NAMESPACE3(_nspNm1,_nspNm2,_nspNm3)                       namespace _nspNm1 { namespace _nspNm2 { namespace _nspNm3 {
#define END_NAMESPACE3                                                  }}}
#define DEC_NM_IN_NSPS_FIELD3(_field,_nspNm1,_nspNm2,_nspNm3)           _field
#define DEC_NM_OUT_NSPS_FIELD3(_field,_nspNm1,_nspNm2,_nspNm3)          _nspNm1 :: _nspNm2 :: _nspNm3 :: _field

#define START_NAMESPACE4(_nspNm1,_nspNm2,_nspNm3,_nspNm4)               namespace _nspNm1 { namespace _nspNm2 { namespace _nspNm3 { namespace _nspNm4 {
#define END_NAMESPACE4                                                  }}}}
#define DEC_NM_IN_NSPS_FIELD4(_field,_nspNm1,_nspNm2,_nspNm3,_nspNm4)   _field
#define DEC_NM_OUT_NSPS_FIELD4(_field,_nspNm1,_nspNm2,_nspNm3,_nspNm4)  _nspNm1 :: _nspNm2 :: _nspNm3 :: _nspNm4 :: _field

#else  // #ifdef __cplusplus

#define THROW2(...)

#define STATIC_CAST2(_type,_dataToConvert)                              ((_type)(_dataToConvert))
#define REINTERPRET_CAST2(_type,_dataToConvert)                         ((_type)(_dataToConvert))


#if 0

#define START_NAMESPACE1(_namespaceName)
#define END_NAMESPACE1
#define DEC_NM_IN_NSPS_FIELD1(_field,_namespaceName)                    ##_namespaceName _ ##_field
#define DEC_NM_OUT_NSPS_FIELD1                                          DEC_NM_IN_NSPS_FIELD1

#define START_NAMESPACE2(_nspNm1,_nspNm2)
#define END_NAMESPACE2
#define DEC_NM_IN_NSPS_FIELD2(_field,_nspNm1,_nspNm2)                   ##_nspNm1 _ ##_nspNm2 _ ##_field
#define DEC_NM_OUT_NSPS_FIELD2                                          DEC_NM_IN_NSPS_FIELD2

#define START_NAMESPACE3(_nspNm1,_nspNm2,_nspNm3)
#define END_NAMESPACE3
#define DEC_NM_IN_NSPS_FIELD3(_field,_nspNm1,_nspNm2)                   ##_nspNm1 _ ##_nspNm2 _ ##_nspNm3 _ ##_field
#define DEC_NM_OUT_NSPS_FIELD3                                          DEC_NM_IN_NSPS_FIELD3

#define START_NAMESPACE4(_nspNm1,_nspNm2,_nspNm3,_nspNm4)
#define END_NAMESPACE4
#define DEC_NM_IN_NSPS_FIELD4(_field,_nspNm1,_nspNm2,_nspNm4)           ##_nspNm1 _ ##_nspNm2 _ ##_nspNm3 _ ##_nspNm4 _ ##_field
#define DEC_NM_OUT_NSPS_FIELD4                                          DEC_NM_IN_NSPS_FIELD4

#endif

#endif  // #ifdef __cplusplus


#ifndef COMPILER_INTERNALS_DEFINED
#define COMPILER_INTERNALS_DEFINED

#ifdef _MSC_VER

#define CPP11_DEFINED

#define CPP_VARIABLE_C2         extern "C"

#define LIKELY_VALUE2(_x,_val)  (_x)
#define LIKELY2(_x)             (_x)
#define UNLIKELY2(_x)           (_x)

#define EXPORT_FROM_LIB2        __declspec(dllexport)
#define IMPORT_FROM_LIB2        __declspec(dllimport)
#define HIDE_SYMBOL2

#define ATTR_CONSTRUCTOR2       
#define ATTR_DESTRUCTOR2       

#elif defined(__GNUC__)

#define CPP_VARIABLE_C2

#define LIKELY2(_x)             __builtin_expect(!!(_x), 1)
#define UNLIKELY2(_x)           __builtin_expect(!!(_x), 0)
#define LIKELY_VALUE2(_x,_val)  __builtin_expect((_x), (_val))

#define EXPORT_FROM_LIB2
#define IMPORT_FROM_LIB2
#define HIDE_SYMBOL2            __attribute__((visibility("hidden")))

#define ATTR_CONSTRUCTOR2       __attribute__ ((__constructor__))
#define ATTR_DESTRUCTOR2        __attribute__ ((__destructor__))

#endif  // #ifdef _MSC_VER

#ifdef __cplusplus

#define VARIABLE_C2     CPP_VARIABLE_C2
#define EXTERN_C2       extern "C"
#define BEGIN_C_DECL2   extern "C"{
#define END_C_DECL2     }

#ifdef CPP11_DEFINED // later on should be checked whether we have cpp11+
#define NEWNULLPTR2     nullptr
#else
#define NEWNULLPTR2     NULL
#define nullptr         NULL
#endif

#ifdef CPP17_DEFINED // later on should be checked whether we have cpp11+
#define FALLTHROUGH2    [[fallthrough]];
#else
#define FALLTHROUGH2
#endif

#elif defined (__CC__)

#else

#define VARIABLE_C2
#define EXTERN_C2      extern
#define BEGIN_C_DECL2
#define END_C_DECL2

#define NEWNULLPTR2     NULL

#endif  // #ifdef __cplusplus

#endif   // #ifndef COMPILER_INTERNALS_DEFINED


#ifdef PITZ_DAQ_DATA_HANDLING_TYPES_CREATING_LIB
#define PITZ_DAQ_DATA_HANDLING_TYPES_EXPORT      EXPORT_FROM_LIB2
#elif defined(PITZ_DAQ_DATA_HANDLING_TYPES_USING_STATIC_LIB_OR_SOURCES)
#define PITZ_DAQ_DATA_HANDLING_TYPES_EXPORT
#else
#define PITZ_DAQ_DATA_HANDLING_TYPES_EXPORT      IMPORT_FROM_LIB2
#endif

#ifdef PITZ_DAQ_DATA_HANDLING_CREATING_LIB
#define PITZ_DAQ_DATA_HANDLING_EXPORT      EXPORT_FROM_LIB2
#elif defined(PITZ_DAQ_DATA_HANDLING_USING_STATIC_LIB_OR_SOURCES)
#define PITZ_DAQ_DATA_HANDLING_EXPORT
#else
#define PITZ_DAQ_DATA_HANDLING_EXPORT      IMPORT_FROM_LIB2
#endif

#endif  // #ifndef PITZ_DAQ_DATA_HANDLING_INTERNAL_H
