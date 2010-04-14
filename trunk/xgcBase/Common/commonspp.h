#ifndef __CLIB_SIMPLE_PREPROCESSOR__
#define __CLIB_SIMPLE_PREPROCESSOR__

	#define CLIB_CONCATENATE_MACRO(x, y)	x##y
	#define CLIB_CONCATENATE_MACRO3(x,y,z)	CLIB_CONCATENATE_MACRO(x##y,z)
	#define CLIB_LINEID1(x, y)				CLIB_CONCATENATE_MACRO(x, y)
	#define CLIB_LINEID(x)					CLIB_LINEID1(x, __LINE__)
	#define CLIB_STRING(X)					#X
	#define CLIB_TOSTRING(X)				CLIB_STRING(X)

	#define CLIB_STATIC_BLOCK(...) \
		namespace { \
		static struct CLIB_LINEID(DUMMY) { CLIB_LINEID(DUMMY)() {      \
		__VA_ARGS__ \
			}                                    \
			} CLIB_LINEID(__dummy__); }

	//enumerates "X" from 1 to num with "INTER" as separator
	// CLIB_ENUM(3,class T, = void CLIB_COMMA) --> class T1 = void, class T2 = void, class T3 = void
	#define CLIB_ENUM(num, X, INTER)                  CLIB_ENUM_ ## num (X, CLIB_UNPAR(INTER) )

	// enumerates using COMMA as separator 
	#define CLIB_ENUM_D(num,X)                        CLIB_ENUM_ ## num (X, CLIB_COMMA)


	// CLIB_PARAM(3, T, P, CLIB_COMMA) --> T1 P1, T2 P2, T3 P3
	#define CLIB_PARAM(num, X, P, INTER)				CLIB_PARAM_ ## num (X, P, CLIB_UNPAR(INTER) )

	// enumerates using COMMA as separator 
	#define CLIB_PARAM_D(num,X,P)						CLIB_PARAM_ ## num (X, P, CLIB_COMMA)

	// Repeats "X" which should be a macro(N) num times, REPEAT_Z starts from 0
	// #define DO(N) T##N;
	// CLIB_REPEAT(3,DO) --> DO(1) DO(2) DO(3) --> T1; T2; T3;
	#define CLIB_REPEAT(num, X)                       CLIB_REPEAT_ ## num (CLIB_UNPAR(X))
	#define CLIB_REPEAT_Z(num, X)                     X(0) CLIB_REPEAT_ ## num (CLIB_UNPAR(X))

	#define CLIB_REPEAT_BASE(num, X, base)            CLIB_REPEAT_BASE_ ## num \
		(CLIB_UNPAR(X),CLIB_UNPAR(base))
	#define CLIB_REPEAT_BASE_Z(num, X, base)          X(0,base) CLIB_REPEAT_BASE_ ## num \
		(CLIB_UNPAR(X), CLIB_UNPAR(base))

	#define CLIB_IF(num,X)                            CLIB_IF_ ## num (CLIB_UNPAR(X))

	#define CLIB_MAIN_REPEAT(num, X)                  CLIB_MAIN_REPEAT_ ## num (CLIB_UNPAR(X))
	#define CLIB_MAIN_REPEAT_Z(num, X)                X(0) CLIB_MAIN_REPEAT_ ## num (CLIB_UNPAR(X))
	#define CLIB_COMMA                                CLIB_UNPAR(,)
	#define CLIB_SPACE 
	#define CLIB_COMMA_IF(num)                        CLIB_IF(num,CLIB_COMMA)

	#define CLIB_UNPAR(...) __VA_ARGS__

	#define CLIB_ENUM_0(X, INTER)  
	#define CLIB_ENUM_1(X, INTER)  X##1
	#define CLIB_ENUM_2(X, INTER)  CLIB_ENUM_1(X,  CLIB_UNPAR(INTER)) INTER X##2
	#define CLIB_ENUM_3(X, INTER)  CLIB_ENUM_2(X,  CLIB_UNPAR(INTER)) INTER X##3
	#define CLIB_ENUM_4(X, INTER)  CLIB_ENUM_3(X,  CLIB_UNPAR(INTER)) INTER X##4
	#define CLIB_ENUM_5(X, INTER)  CLIB_ENUM_4(X,  CLIB_UNPAR(INTER)) INTER X##5
	#define CLIB_ENUM_6(X, INTER)  CLIB_ENUM_5(X,  CLIB_UNPAR(INTER)) INTER X##6
	#define CLIB_ENUM_7(X, INTER)  CLIB_ENUM_6(X,  CLIB_UNPAR(INTER)) INTER X##7
	#define CLIB_ENUM_8(X, INTER)  CLIB_ENUM_7(X,  CLIB_UNPAR(INTER)) INTER X##8
	#define CLIB_ENUM_9(X, INTER)  CLIB_ENUM_8(X,  CLIB_UNPAR(INTER)) INTER X##9
	#define CLIB_ENUM_10(X, INTER) CLIB_ENUM_9(X,  CLIB_UNPAR(INTER)) INTER X##10
	#define CLIB_ENUM_11(X, INTER) CLIB_ENUM_10(X, CLIB_UNPAR(INTER)) INTER X##11
	#define CLIB_ENUM_12(X, INTER) CLIB_ENUM_11(X, CLIB_UNPAR(INTER)) INTER X##12
	#define CLIB_ENUM_13(X, INTER) CLIB_ENUM_12(X, CLIB_UNPAR(INTER)) INTER X##13
	#define CLIB_ENUM_14(X, INTER) CLIB_ENUM_13(X, CLIB_UNPAR(INTER)) INTER X##14
	#define CLIB_ENUM_15(X, INTER) CLIB_ENUM_14(X, CLIB_UNPAR(INTER)) INTER X##15
	#define CLIB_ENUM_16(X, INTER) CLIB_ENUM_15(X, CLIB_UNPAR(INTER)) INTER X##16
	#define CLIB_ENUM_17(X, INTER) CLIB_ENUM_16(X, CLIB_UNPAR(INTER)) INTER X##17
	#define CLIB_ENUM_18(X, INTER) CLIB_ENUM_17(X, CLIB_UNPAR(INTER)) INTER X##18
	#define CLIB_ENUM_19(X, INTER) CLIB_ENUM_18(X, CLIB_UNPAR(INTER)) INTER X##19
	#define CLIB_ENUM_20(X, INTER) CLIB_ENUM_19(X, CLIB_UNPAR(INTER)) INTER X##20
	#define CLIB_ENUM_21(X, INTER) CLIB_ENUM_20(X, CLIB_UNPAR(INTER)) INTER X##21
	#define CLIB_ENUM_22(X, INTER) CLIB_ENUM_21(X, CLIB_UNPAR(INTER)) INTER X##22
	#define CLIB_ENUM_23(X, INTER) CLIB_ENUM_22(X, CLIB_UNPAR(INTER)) INTER X##23
	#define CLIB_ENUM_24(X, INTER) CLIB_ENUM_23(X, CLIB_UNPAR(INTER)) INTER X##24
	#define CLIB_ENUM_25(X, INTER) CLIB_ENUM_24(X, CLIB_UNPAR(INTER)) INTER X##25
	#define CLIB_ENUM_26(X, INTER) CLIB_ENUM_25(X, CLIB_UNPAR(INTER)) INTER X##26
	#define CLIB_ENUM_27(X, INTER) CLIB_ENUM_26(X, CLIB_UNPAR(INTER)) INTER X##27
	#define CLIB_ENUM_28(X, INTER) CLIB_ENUM_27(X, CLIB_UNPAR(INTER)) INTER X##28
	#define CLIB_ENUM_29(X, INTER) CLIB_ENUM_28(X, CLIB_UNPAR(INTER)) INTER X##29
	#define CLIB_ENUM_30(X, INTER) CLIB_ENUM_29(X, CLIB_UNPAR(INTER)) INTER X##30
	#define CLIB_ENUM_31(X, INTER) CLIB_ENUM_30(X, CLIB_UNPAR(INTER)) INTER X##31
	#define CLIB_ENUM_32(X, INTER) CLIB_ENUM_31(X, CLIB_UNPAR(INTER)) INTER X##32
	#define CLIB_ENUM_MAX(X, INTER) CLIB_ENUM_10(X, INTER) /* Change this up to 32 */

	#define CLIB_PARAM_0(X, P, INTER)  
	#define CLIB_PARAM_1(X, P, INTER)  X##1 P##1
	#define CLIB_PARAM_2(X, P, INTER)  CLIB_PARAM_1(X, P,  CLIB_UNPAR(INTER)) INTER X##2 P##2
	#define CLIB_PARAM_3(X, P, INTER)  CLIB_PARAM_2(X, P,  CLIB_UNPAR(INTER)) INTER X##3 P##3
	#define CLIB_PARAM_4(X, P, INTER)  CLIB_PARAM_3(X, P,  CLIB_UNPAR(INTER)) INTER X##4 P##4
	#define CLIB_PARAM_5(X, P, INTER)  CLIB_PARAM_4(X, P,  CLIB_UNPAR(INTER)) INTER X##5 P##5
	#define CLIB_PARAM_6(X, P, INTER)  CLIB_PARAM_5(X, P,  CLIB_UNPAR(INTER)) INTER X##6 P##6
	#define CLIB_PARAM_7(X, P, INTER)  CLIB_PARAM_6(X, P,  CLIB_UNPAR(INTER)) INTER X##7 P##7
	#define CLIB_PARAM_8(X, P, INTER)  CLIB_PARAM_7(X, P,  CLIB_UNPAR(INTER)) INTER X##8 P##8
	#define CLIB_PARAM_9(X, P, INTER)  CLIB_PARAM_8(X, P,  CLIB_UNPAR(INTER)) INTER X##9 P##9
	#define CLIB_PARAM_10(X, P, INTER) CLIB_PARAM_9(X, P,  CLIB_UNPAR(INTER)) INTER X##10 P##10
	#define CLIB_PARAM_11(X, P, INTER) CLIB_PARAM_10(X, P, CLIB_UNPAR(INTER)) INTER X##11 P##11
	#define CLIB_PARAM_12(X, P, INTER) CLIB_PARAM_11(X, P, CLIB_UNPAR(INTER)) INTER X##12 P##12
	#define CLIB_PARAM_13(X, P, INTER) CLIB_PARAM_12(X, P, CLIB_UNPAR(INTER)) INTER X##13 P##13
	#define CLIB_PARAM_14(X, P, INTER) CLIB_PARAM_13(X, P, CLIB_UNPAR(INTER)) INTER X##14 P##14
	#define CLIB_PARAM_15(X, P, INTER) CLIB_PARAM_14(X, P, CLIB_UNPAR(INTER)) INTER X##15 P##15
	#define CLIB_PARAM_16(X, P, INTER) CLIB_PARAM_15(X, P, CLIB_UNPAR(INTER)) INTER X##16 P##16
	#define CLIB_PARAM_17(X, P, INTER) CLIB_PARAM_16(X, P, CLIB_UNPAR(INTER)) INTER X##17 P##17
	#define CLIB_PARAM_18(X, P, INTER) CLIB_PARAM_17(X, P, CLIB_UNPAR(INTER)) INTER X##18 P##18
	#define CLIB_PARAM_19(X, P, INTER) CLIB_PARAM_18(X, P, CLIB_UNPAR(INTER)) INTER X##19 P##19
	#define CLIB_PARAM_20(X, P, INTER) CLIB_PARAM_19(X, P, CLIB_UNPAR(INTER)) INTER X##20 P##20
	#define CLIB_PARAM_21(X, P, INTER) CLIB_PARAM_20(X, P, CLIB_UNPAR(INTER)) INTER X##21 P##21
	#define CLIB_PARAM_22(X, P, INTER) CLIB_PARAM_21(X, P, CLIB_UNPAR(INTER)) INTER X##22 P##22
	#define CLIB_PARAM_23(X, P, INTER) CLIB_PARAM_22(X, P, CLIB_UNPAR(INTER)) INTER X##23 P##23
	#define CLIB_PARAM_24(X, P, INTER) CLIB_PARAM_23(X, P, CLIB_UNPAR(INTER)) INTER X##24 P##24
	#define CLIB_PARAM_25(X, P, INTER) CLIB_PARAM_24(X, P, CLIB_UNPAR(INTER)) INTER X##25 P##25
	#define CLIB_PARAM_26(X, P, INTER) CLIB_PARAM_25(X, P, CLIB_UNPAR(INTER)) INTER X##26 P##26
	#define CLIB_PARAM_27(X, P, INTER) CLIB_PARAM_26(X, P, CLIB_UNPAR(INTER)) INTER X##27 P##27
	#define CLIB_PARAM_28(X, P, INTER) CLIB_PARAM_27(X, P, CLIB_UNPAR(INTER)) INTER X##28 P##28
	#define CLIB_PARAM_29(X, P, INTER) CLIB_PARAM_28(X, P, CLIB_UNPAR(INTER)) INTER X##29 P##29
	#define CLIB_PARAM_30(X, P, INTER) CLIB_PARAM_29(X, P, CLIB_UNPAR(INTER)) INTER X##30 P##30
	#define CLIB_PARAM_31(X, P, INTER) CLIB_PARAM_30(X, P, CLIB_UNPAR(INTER)) INTER X##31 P##31
	#define CLIB_PARAM_32(X, P, INTER) CLIB_PARAM_31(X, P, CLIB_UNPAR(INTER)) INTER X##32 P##32
	#define CLIB_PARAM_MAX(X, P, INTER) CLIB_PARAM_10(X, P, INTER) /* Change this up to 32 */

	#define CLIB_REPEAT_0(X) 
	#define CLIB_REPEAT_1(X) X(1)
	#define CLIB_REPEAT_2(X) CLIB_REPEAT_1(X) X(2) 
	#define CLIB_REPEAT_3(X) CLIB_REPEAT_2(X) X(3) 
	#define CLIB_REPEAT_4(X) CLIB_REPEAT_3(X) X(4) 
	#define CLIB_REPEAT_5(X) CLIB_REPEAT_4(X) X(5) 
	#define CLIB_REPEAT_6(X) CLIB_REPEAT_5(X) X(6) 
	#define CLIB_REPEAT_7(X) CLIB_REPEAT_6(X) X(7) 
	#define CLIB_REPEAT_8(X) CLIB_REPEAT_7(X) X(8) 
	#define CLIB_REPEAT_9(X) CLIB_REPEAT_8(X) X(9) 
	#define CLIB_REPEAT_10(X) CLIB_REPEAT_9(X) X(10) 
	#define CLIB_REPEAT_11(X) CLIB_REPEAT_10(X) X(11) 
	#define CLIB_REPEAT_12(X) CLIB_REPEAT_11(X) X(12) 
	#define CLIB_REPEAT_13(X) CLIB_REPEAT_12(X) X(13) 
	#define CLIB_REPEAT_14(X) CLIB_REPEAT_13(X) X(14) 
	#define CLIB_REPEAT_15(X) CLIB_REPEAT_14(X) X(15) 
	#define CLIB_REPEAT_16(X) CLIB_REPEAT_15(X) X(16) 
	#define CLIB_REPEAT_17(X) CLIB_REPEAT_16(X) X(17) 
	#define CLIB_REPEAT_18(X) CLIB_REPEAT_17(X) X(18) 
	#define CLIB_REPEAT_19(X) CLIB_REPEAT_18(X) X(19) 
	#define CLIB_REPEAT_20(X) CLIB_REPEAT_19(X) X(20) 
	#define CLIB_REPEAT_21(X) CLIB_REPEAT_20(X) X(21) 
	#define CLIB_REPEAT_22(X) CLIB_REPEAT_21(X) X(22) 
	#define CLIB_REPEAT_23(X) CLIB_REPEAT_22(X) X(23) 
	#define CLIB_REPEAT_24(X) CLIB_REPEAT_23(X) X(24) 
	#define CLIB_REPEAT_25(X) CLIB_REPEAT_24(X) X(25) 
	#define CLIB_REPEAT_26(X) CLIB_REPEAT_25(X) X(26) 
	#define CLIB_REPEAT_27(X) CLIB_REPEAT_26(X) X(27) 
	#define CLIB_REPEAT_28(X) CLIB_REPEAT_27(X) X(28) 
	#define CLIB_REPEAT_29(X) CLIB_REPEAT_28(X) X(29) 
	#define CLIB_REPEAT_30(X) CLIB_REPEAT_29(X) X(30) 
	#define CLIB_REPEAT_31(X) CLIB_REPEAT_30(X) X(31) 
	#define CLIB_REPEAT_32(X) CLIB_REPEAT_31(X) X(32) 
	#define CLIB_REPEAT_MAX(X) CLIB_REPEAT_10(X)  /* Change this up to 32 */

	#define CLIB_REPEAT_BASE_0(X,base) 
	#define CLIB_REPEAT_BASE_1(X,base) X(1, base)
	#define CLIB_REPEAT_BASE_2(X,base) CLIB_REPEAT_BASE_1(X,base) X(2, base) 
	#define CLIB_REPEAT_BASE_3(X,base) CLIB_REPEAT_BASE_2(X,base) X(3, base) 
	#define CLIB_REPEAT_BASE_4(X,base) CLIB_REPEAT_BASE_3(X,base) X(4, base) 
	#define CLIB_REPEAT_BASE_5(X,base) CLIB_REPEAT_BASE_4(X,base) X(5, base) 
	#define CLIB_REPEAT_BASE_6(X,base) CLIB_REPEAT_BASE_5(X,base) X(6, base) 
	#define CLIB_REPEAT_BASE_7(X,base) CLIB_REPEAT_BASE_6(X,base) X(7, base) 
	#define CLIB_REPEAT_BASE_8(X,base) CLIB_REPEAT_BASE_7(X,base) X(8, base) 
	#define CLIB_REPEAT_BASE_9(X,base) CLIB_REPEAT_BASE_8(X,base) X(9, base) 
	#define CLIB_REPEAT_BASE_10(X,base) CLIB_REPEAT_BASE_9(X,base) X(10, base) 
	#define CLIB_REPEAT_BASE_11(X,base) CLIB_REPEAT_BASE_10(X,base) X(11, base) 
	#define CLIB_REPEAT_BASE_12(X,base) CLIB_REPEAT_BASE_11(X,base) X(12, base) 
	#define CLIB_REPEAT_BASE_13(X,base) CLIB_REPEAT_BASE_12(X,base) X(13, base) 
	#define CLIB_REPEAT_BASE_14(X,base) CLIB_REPEAT_BASE_13(X,base) X(14, base) 
	#define CLIB_REPEAT_BASE_15(X,base) CLIB_REPEAT_BASE_14(X,base) X(15, base) 
	#define CLIB_REPEAT_BASE_16(X,base) CLIB_REPEAT_BASE_15(X,base) X(16, base) 
	#define CLIB_REPEAT_BASE_17(X,base) CLIB_REPEAT_BASE_16(X,base) X(17, base) 
	#define CLIB_REPEAT_BASE_18(X,base) CLIB_REPEAT_BASE_17(X,base) X(18, base) 
	#define CLIB_REPEAT_BASE_19(X,base) CLIB_REPEAT_BASE_18(X,base) X(19, base) 
	#define CLIB_REPEAT_BASE_20(X,base) CLIB_REPEAT_BASE_19(X,base) X(20, base) 
	#define CLIB_REPEAT_BASE_21(X,base) CLIB_REPEAT_BASE_20(X,base) X(21, base) 
	#define CLIB_REPEAT_BASE_22(X,base) CLIB_REPEAT_BASE_21(X,base) X(22, base) 
	#define CLIB_REPEAT_BASE_23(X,base) CLIB_REPEAT_BASE_22(X,base) X(23, base) 
	#define CLIB_REPEAT_BASE_24(X,base) CLIB_REPEAT_BASE_23(X,base) X(24, base) 
	#define CLIB_REPEAT_BASE_25(X,base) CLIB_REPEAT_BASE_24(X,base) X(25, base) 
	#define CLIB_REPEAT_BASE_26(X,base) CLIB_REPEAT_BASE_25(X,base) X(26, base) 
	#define CLIB_REPEAT_BASE_27(X,base) CLIB_REPEAT_BASE_26(X,base) X(27, base) 
	#define CLIB_REPEAT_BASE_28(X,base) CLIB_REPEAT_BASE_27(X,base) X(28, base) 
	#define CLIB_REPEAT_BASE_29(X,base) CLIB_REPEAT_BASE_28(X,base) X(29, base) 
	#define CLIB_REPEAT_BASE_30(X,base) CLIB_REPEAT_BASE_29(X,base) X(30, base) 
	#define CLIB_REPEAT_BASE_31(X,base) CLIB_REPEAT_BASE_30(X,base) X(31, base) 
	#define CLIB_REPEAT_BASE_32(X,base) CLIB_REPEAT_BASE_31(X,base) X(32, base) 
	#define CLIB_REPEAT_BASE_MAX(X,base) CLIB_REPEAT_BASE_10(X,base)  /* Change this up to 32 */

	#define CLIB_MAIN_REPEAT_1(X) X(1)
	#define CLIB_MAIN_REPEAT_2(X) CLIB_MAIN_REPEAT_1(X) X(2) 
	#define CLIB_MAIN_REPEAT_3(X) CLIB_MAIN_REPEAT_2(X) X(3) 
	#define CLIB_MAIN_REPEAT_4(X) CLIB_MAIN_REPEAT_3(X) X(4) 
	#define CLIB_MAIN_REPEAT_5(X) CLIB_MAIN_REPEAT_4(X) X(5) 
	#define CLIB_MAIN_REPEAT_6(X) CLIB_MAIN_REPEAT_5(X) X(6) 
	#define CLIB_MAIN_REPEAT_7(X) CLIB_MAIN_REPEAT_6(X) X(7) 
	#define CLIB_MAIN_REPEAT_8(X) CLIB_MAIN_REPEAT_7(X) X(8) 
	#define CLIB_MAIN_REPEAT_9(X) CLIB_MAIN_REPEAT_8(X) X(9) 
	#define CLIB_MAIN_REPEAT_10(X) CLIB_MAIN_REPEAT_9(X) X(10) 
	#define CLIB_MAIN_REPEAT_11(X) CLIB_MAIN_REPEAT_10(X) X(11) 
	#define CLIB_MAIN_REPEAT_12(X) CLIB_MAIN_REPEAT_11(X) X(12) 
	#define CLIB_MAIN_REPEAT_13(X) CLIB_MAIN_REPEAT_12(X) X(13) 
	#define CLIB_MAIN_REPEAT_14(X) CLIB_MAIN_REPEAT_13(X) X(14) 
	#define CLIB_MAIN_REPEAT_15(X) CLIB_MAIN_REPEAT_14(X) X(15) 
	#define CLIB_MAIN_REPEAT_16(X) CLIB_MAIN_REPEAT_15(X) X(16) 
	#define CLIB_MAIN_REPEAT_17(X) CLIB_MAIN_REPEAT_16(X) X(17) 
	#define CLIB_MAIN_REPEAT_18(X) CLIB_MAIN_REPEAT_17(X) X(18) 
	#define CLIB_MAIN_REPEAT_19(X) CLIB_MAIN_REPEAT_18(X) X(19) 
	#define CLIB_MAIN_REPEAT_20(X) CLIB_MAIN_REPEAT_19(X) X(20) 
	#define CLIB_MAIN_REPEAT_21(X) CLIB_MAIN_REPEAT_20(X) X(21) 
	#define CLIB_MAIN_REPEAT_22(X) CLIB_MAIN_REPEAT_21(X) X(22) 
	#define CLIB_MAIN_REPEAT_23(X) CLIB_MAIN_REPEAT_22(X) X(23) 
	#define CLIB_MAIN_REPEAT_24(X) CLIB_MAIN_REPEAT_23(X) X(24) 
	#define CLIB_MAIN_REPEAT_25(X) CLIB_MAIN_REPEAT_24(X) X(25) 
	#define CLIB_MAIN_REPEAT_26(X) CLIB_MAIN_REPEAT_25(X) X(26) 
	#define CLIB_MAIN_REPEAT_27(X) CLIB_MAIN_REPEAT_26(X) X(27) 
	#define CLIB_MAIN_REPEAT_28(X) CLIB_MAIN_REPEAT_27(X) X(28) 
	#define CLIB_MAIN_REPEAT_29(X) CLIB_MAIN_REPEAT_28(X) X(29) 
	#define CLIB_MAIN_REPEAT_30(X) CLIB_MAIN_REPEAT_29(X) X(30) 
	#define CLIB_MAIN_REPEAT_31(X) CLIB_MAIN_REPEAT_30(X) X(31) 
	#define CLIB_MAIN_REPEAT_32(X) CLIB_MAIN_REPEAT_31(X) X(32) 
	#define CLIB_MAIN_REPEAT_MAX(X) CLIB_MAIN_REPEAT_10(X)  /* Change this up to 32 */

	#define CLIB_IF_0(X) 
	#define CLIB_IF_1(X) X
	#define CLIB_IF_2(X) X
	#define CLIB_IF_3(X) X
	#define CLIB_IF_4(X) X
	#define CLIB_IF_5(X) X
	#define CLIB_IF_6(X) X
	#define CLIB_IF_7(X) X
	#define CLIB_IF_8(X) X
	#define CLIB_IF_9(X) X
	#define CLIB_IF_10(X) X
	#define CLIB_IF_11(X) X
	#define CLIB_IF_12(X) X
	#define CLIB_IF_13(X) X
	#define CLIB_IF_14(X) X
	#define CLIB_IF_15(X) X
	#define CLIB_IF_16(X) X
	#define CLIB_IF_17(X) X
	#define CLIB_IF_18(X) X
	#define CLIB_IF_19(X) X
	#define CLIB_IF_20(X) X
	#define CLIB_IF_21(X) X
	#define CLIB_IF_22(X) X
	#define CLIB_IF_23(X) X
	#define CLIB_IF_24(X) X
	#define CLIB_IF_25(X) X
	#define CLIB_IF_26(X) X
	#define CLIB_IF_27(X) X
	#define CLIB_IF_28(X) X
	#define CLIB_IF_29(X) X
	#define CLIB_IF_30(X) X
	#define CLIB_IF_31(X) X
	#define CLIB_IF_32(X) X
	#define CLIB_IF_MAX(X) CLIB_IF_10(X) /* Change this up to 32 */

#endif
