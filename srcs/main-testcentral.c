/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:31:32 by enennige          #+#    #+#             */
/*   Updated: 2018/04/24 16:57:09 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "limits.h"
#include <wchar.h>
#include <locale.h>

/*This main is primarily for testing output*/

int main(void)
{
	
	setlocale(LC_ALL, "");	
	
	/*
	printf("\nCHAR:\n");
	printf("num bytes: %d\n", 1);
	printf("signed range:	%d	to	%d\n", SCHAR_MIN, SCHAR_MAX);
	printf("unsigned range:	%d	to	%d\n", 0, UCHAR_MAX);

	printf("\nSHORT:\n");
	printf("num bytes: %d\n", 2);
	printf("signed range:	%d	to	%d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned range:	%d	to	%d\n", 0, USHRT_MAX);

	printf("\nINT:\n");
	printf("num bytes: %d\n", 4);
	printf("signed range:	%d	to	%d\n", INT_MIN, INT_MAX);
	printf("unsigned range:	%d	to	%u\n", 0, UINT_MAX);
	
	printf("\nLONG: (FAKE NEWS)\n");
	printf("num bytes: ?? %d\n", 4);
	printf("signed range:	%ld	to	%ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned range:	%d	to	%lu\n", 0, ULONG_MAX);
	
	printf("\nLONGLONG:\n");
	printf("num bytes: ?? %d\n", 8);
	printf("signed range:	%lld	to	%lld\n", LLONG_MIN, LLONG_MAX);
	printf("unsigned range:	%d	to	%llu\n", 0, ULLONG_MAX);
	
	printf("\nINTMAX:\n");
	printf("num bytes: ?? %d\n", 0);
	printf("signed range:	%jd	to	%jd\n", (uintmax_t)INTMAX_MIN, (uintmax_t)INTMAX_MAX);
	printf("unsigned range:	%d	to	%ju\n", 0, (uintmax_t)UINTMAX_MAX);
	
	printf("\nWCHAR:\n");
	printf("range:	%d	to	%d\n", WCHAR_MIN, WCHAR_MAX);

	printf("\nWINT:\n");
	printf("range:	%d	to	%d\n", WINT_MIN, WINT_MAX);

	*/


	printf("\n_.~****************LETS TEST SOME THINGS**************~._\n");
	printf("\n\n_.~***************************************************~._\n");
	printf("_.~*                     SIGNED                      *~._\n");
	printf("_.~***************************************************~._\n");

	printf("\n_*CHAR*_\n\n");

	char c = 'a';
	char c_max = CHAR_MAX;
	char c_min = CHAR_MIN;
	printf("printf c:	%c\n", c);
	ft_printf("my c:		%c\n", c);
	printf("printf c_min:	%c\n", c_min);
	ft_printf("my c_min:	%c\n", c_min);
	printf("printf c_max:	%c\n", c_max);
	ft_printf("my c_max:	%c\n\n", c_max);
	
	printf("printf hhd:	%hhd\n", c);
	ft_printf("my hhd:		%hhd\n", c);
	printf("printf c_min:	%hhd\n", c_min);
	ft_printf("my c_min:	%hhd\n", c_min);
	printf("printf c_max:	%hhd\n", c_max);
	ft_printf("my c_max:	%hhd\n\n", c_max);
	
	printf("printf hhi:	%hhi\n", c);
	ft_printf("my hhi:		%hhi\n", c);
	printf("printf hhi_min:	%hhi\n", c_min);
	ft_printf("my hhi_min:	%hhi\n", c_min);
	printf("printf hhi_max:	%hhi\n", c_max);
	ft_printf("my hhi_max:	%hhi\n\n", c_max);
	
	printf("\n_*SHORT*_\n\n");

	short hd = 12;
	short hd_min = -32768;
	short hd_max = 32767;
	
	printf("printf hd:	%hd\n", hd);
	ft_printf("my hd:		%hd\n", hd);
	printf("printf hd:	%hd\n", hd_min);
	ft_printf("my hd:		%hd\n", hd_min);
	printf("printf hd:	%hd\n", hd_max);
	ft_printf("my hd:		%hd\n\n", hd_max);
	
	printf("printf hi:	%hd\n", hd);
	ft_printf("my hi:		%hd\n", hd);
	printf("printf hi:	%hd\n", hd_min);
	ft_printf("my hi:		%hd\n", hd_min);
	printf("printf hi:	%hd\n", hd_max);
	ft_printf("my hi:		%hd\n\n", hd_max);
	
	printf("\n_*INT*_\n\n");

	int	d = -10000000;

	int d_min = -2147483648;
	int d_max = 2147483647;
	
	printf("printf d:	%d\n", d);
	ft_printf("my d:		%d\n", d);
	printf("printf d:	%d\n", d_min);
	ft_printf("my d:		%d\n", d_min);
	printf("printf d:	%d\n", d_max);
	ft_printf("my d:		%d\n\n", d_max);
	
	printf("printf i:	%d\n", d);
	ft_printf("my i:		%d\n", d);
	printf("printf i:	%d\n", d_min);
	ft_printf("my i:		%d\n", d_min);
	printf("printf i:	%d\n", d_max);
	ft_printf("my i:		%d\n\n", d_max);
	
	printf("printf D:	%D\n", d);
	ft_printf("my D:		%D\n", d);
	printf("printf D:	%D\n", d_min);
	ft_printf("my D:		%D\n", d_min);
	printf("printf D:	%D\n", d_max);
	ft_printf("my D:		%D\n", d_max);

	printf("\n_*LONG*_\n\n");

	long l = -42;
	long l_min = LONG_MIN;
	long l_max = LONG_MAX;
	
	printf("printf ld:	%ld\n", l);
	ft_printf("my ld:		%ld\n", l);
	printf("printf ld:	%ld\n", l_min);
	ft_printf("my ld:		%ld\n", l_min);
	printf("printf ld:	%ld\n", l_max);
	ft_printf("my ld:		%ld\n\n", l_max);
	
	printf("printf li:	%li\n", l);
	ft_printf("my li:		%li\n", l);
	printf("printf li:	%li\n", l_min);
	ft_printf("my li:		%li\n", l_min);
	printf("printf li:	%li\n", l_max);
	ft_printf("my li:		%li\n\n", l_max);
	
	printf("\n_*LONG LONG*_\n\n");

	long long ll = -42;
	long long ll_min = LLONG_MIN;
	long long ll_max = LLONG_MAX;
	
	printf("printf lld:	%lld\n", ll);
	ft_printf("my lld:		%lld\n", ll);
	printf("printf lld:	%lld\n", ll_min);
	ft_printf("my lld:		%lld\n", ll_min);
	printf("printf lld:	%lld\n", ll_max);
	ft_printf("my ld:		%lld\n\n", ll_max);
	
	printf("printf li:	%lli\n", ll);
	ft_printf("my lli:		%lli\n", ll);
	printf("printf lli:	%lli\n", ll_min);
	ft_printf("my lli:		%lli\n", ll_min);
	printf("printf lli:	%lli\n", ll_max);
	ft_printf("my lli:		%lli\n", ll_max);

	printf("\n_*INTMAX_T*_\n\n");

	intmax_t imax = -42;
	intmax_t imax_min = INTMAX_MIN;
	intmax_t imax_max = INTMAX_MAX;
	
	printf("printf jd:	%jd\n", imax);
	ft_printf("my jd:		%jd\n", imax);
	printf("printf jd:	%jd\n", imax_min);
	ft_printf("my jd:		%jd\n", imax_min);
	printf("printf jd:	%jd\n", imax_max);
	ft_printf("my jd:		%jd\n\n", imax_max);
	
	printf("printf ji:	%ji\n", imax);
	ft_printf("my ji:		%ji\n", imax);
	printf("printf ji:	%ji\n", imax_min);
	ft_printf("my ji:		%ji\n", imax_min);
	printf("printf ji:	%ji\n", imax_max);
	ft_printf("my ji:		%ji\n", imax_max);
	
	printf("\n_*SIZE_T*_\n\n");

	size_t sizet = -42;
	size_t	sizet_min = INTMAX_MIN;
	size_t	 sizet_max = INTMAX_MAX;
	
	printf("printf zd:	%zd\n", sizet);
	ft_printf("my zd:		%zd\n", sizet);
	printf("printf zd:	%zd\n", sizet_min);
	ft_printf("my zd:		%zd\n", sizet_min);
	printf("printf zd:	%zd\n", sizet_max);
	ft_printf("my zd:		%zd\n\n", sizet_max);
	
	printf("printf zi:	%zi\n", sizet);
	ft_printf("my zi:		%zi\n", sizet);
	printf("printf zi:	%zi\n", sizet_min);
	ft_printf("my zi:		%zi\n", sizet_min);
	printf("printf zi:	%zi\n", sizet_max);
	ft_printf("my zi:		%zi\n", sizet_max);


	printf("\n\n_.~***************************************************~._\n");
	printf("_.~*                    UNSIGNED                     *~._\n");
	printf("_.~***************************************************~._\n");
	
	printf("\n_*UNSIGNED CHAR*_\n\n");

	unsigned char  uchar = 100;
	unsigned char uchar_min = 0;
	unsigned char uchar_max = UCHAR_MAX;
	
	printf("printf hhu:	%hhu\n", uchar);
	ft_printf("my hhu:		%hhu\n", uchar);
	printf("printf hhu:	%hhu\n", uchar_min);
	ft_printf("my hhu:		%hhu\n", uchar_min);
	printf("printf hhu:	%hhu\n", uchar_max);
	ft_printf("my hhu:		%hhu\n\n", uchar_max);
	
	printf("printf hho:	%hho\n", uchar);
	ft_printf("my hho:		%hho\n", uchar);
	printf("printf hho:	%hho\n", uchar_min);
	ft_printf("my hho:		%hho\n", uchar_min);
	printf("printf hho:	%hho\n", uchar_max);
	ft_printf("my hho:		%hho\n\n", uchar_max);
	
	printf("printf hhx:	%hhx\n", uchar);
	ft_printf("my hhx:		%hhx\n", uchar);
	printf("printf hhx:	%hhx\n", uchar_min);
	ft_printf("my hhx:		%hhx\n", uchar_min);
	printf("printf hhx:	%hhx\n", uchar_max);
	ft_printf("my hhx:		%hhx\n\n", uchar_max);
	
	printf("printf hhX:	%hhX\n", uchar);
	ft_printf("my hhX:		%hhX\n", uchar);
	printf("printf hhX:	%hhX\n", uchar_min);
	ft_printf("my hhX:		%hhX\n", uchar_min);
	printf("printf hhX:	%hhX\n", uchar_max);
	ft_printf("my hhX:		%hhX\n\n", uchar_max);
	
	printf("\n_*UNSIGNED SHORT*_\n\n");

	unsigned short ushort = 100;
	unsigned short ushort_min = 0;
	unsigned short ushort_max = UCHAR_MAX;
	
	printf("printf hu:	%hu\n", ushort);
	ft_printf("my hu:		%hu\n", ushort);
	printf("printf hu:	%hu\n", ushort_min);
	ft_printf("my hu:		%hu\n", ushort_min);
	printf("printf hu:	%hu\n", ushort_max);
	ft_printf("my hu:		%hu\n\n", ushort_max);
	
	printf("printf ho:	%ho\n", ushort);
	ft_printf("my ho:		%ho\n", ushort);
	printf("printf ho:	%ho\n", ushort_min);
	ft_printf("my ho:		%ho\n", ushort_min);
	printf("printf ho:	%ho\n", ushort_max);
	ft_printf("my ho:		%ho\n\n", ushort_max);
	
	printf("printf hx:	%hx\n", ushort);
	ft_printf("my hx:		%hx\n", ushort);
	printf("printf hx:	%hx\n", ushort_min);
	ft_printf("my hx:		%hx\n", ushort_min);
	printf("printf hx:	%hx\n", ushort_max);
	ft_printf("my hx:		%hx\n\n", ushort_max);
	
	printf("printf hX:	%hX\n", ushort);
	ft_printf("my hX:		%hX\n", ushort);
	printf("printf hX:	%hX\n", ushort_min);
	ft_printf("my hX:		%hX\n", ushort_min);
	printf("printf hX:	%hX\n", ushort_max);
	ft_printf("my hX:		%hX\n\n", ushort_max);
	
	printf("\n_*UNSIGNED INT*_\n\n");

	unsigned int uint = 41424344;
	unsigned int uint_min = 0;
	unsigned int uint_max = UINT_MAX;
	
	printf("printf u:	%u\n", uint);
	ft_printf("my u:		%u\n", uint);
	printf("printf u:	%u\n", uint_min);
	ft_printf("my u:		%u\n", uint_min);
	printf("printf u:	%u\n", uint_max);
	ft_printf("my u:		%u\n\n", uint_max);
	
	printf("printf o:	%o\n", uint);
	ft_printf("my o:		%o\n", uint);
	printf("printf o:	%o\n", uint_min);
	ft_printf("my o:		%o\n", uint_min);
	printf("printf o:	%o\n", uint_max);
	ft_printf("my o:		%o\n\n", uint_max);
	
	printf("printf x:	%x\n", uint);
	ft_printf("my x:		%x\n", uint);
	printf("printf x:	%x\n", uint_min);
	ft_printf("my x:		%x\n", uint_min);
	printf("printf x:	%x\n", uint_max);
	ft_printf("my x:		%x\n\n", uint_max);
	
	printf("printf X:	%X\n", uint);
	ft_printf("my X:		%X\n", uint);
	printf("printf X:	%X\n", uint_min);
	ft_printf("my X:		%X\n", uint_min);
	printf("printf X:	%X\n", uint_max);
	ft_printf("my X:		%X\n\n", uint_max);
	
	printf("printf U:	%U\n", uint);
	ft_printf("my U:		%U\n", uint);
	printf("printf U:	%U\n", uint_min);
	ft_printf("my U:		%U\n", uint_min);
	printf("printf U:	%U\n", uint_max);
	ft_printf("my U:		%U\n\n", uint_max);
	
	printf("printf O:	%O\n", uint);
	ft_printf("my O:		%O\n", uint);
	printf("printf O:	%O\n", uint_min);
	ft_printf("my O:		%O\n", uint_min);
	printf("printf O:	%O\n", uint_max);
	ft_printf("my O:		%O\n\n", uint_max);
	
	printf("\n_*UNSIGNED LONG*_\n\n");

	unsigned long ulong = 424242424242;
	unsigned long ulong_min = 0;
	unsigned long ulong_max = ULONG_MAX;
	
	printf("printf lu:	%lu\n", ulong);
	ft_printf("my lu:		%lu\n", ulong);
	printf("printf lu:	%lu\n", ulong_min);
	ft_printf("my lu:		%lu\n", ulong_min);
	printf("printf lu:	%lu\n", ulong_max);
	ft_printf("my lu:		%lu\n\n", ulong_max);
	
	printf("printf lo:	%lo\n", ulong);
	ft_printf("my lo:		%lo\n", ulong);
	printf("printf lo:	%lo\n", ulong_min);
	ft_printf("my lo:		%lo\n", ulong_min);
	printf("printf lo:	%lo\n", ulong_max);
	ft_printf("my lo:		%lo\n\n", ulong_max);
	
	printf("printf lx:	%lx\n", ulong);
	ft_printf("my lx:		%lx\n", ulong);
	printf("printf lx:	%lx\n", ulong_min);
	ft_printf("my lx:		%lx\n", ulong_min);
	printf("printf lx:	%lx\n", ulong_max);
	ft_printf("my lx:		%lx\n\n", ulong_max);
	
	printf("printf lX:	%lX\n", ulong);
	ft_printf("my lX:		%lX\n", ulong);
	printf("printf lX:	%lX\n", ulong_min);
	ft_printf("my lX:		%lX\n", ulong_min);
	printf("printf lX:	%lX\n", ulong_max);
	ft_printf("my lX:		%lX\n\n", ulong_max);
	
	printf("\n_*UNSIGNED LONG LONG*_\n\n");

	unsigned long long ullong = 424242424242;
	unsigned long long ullong_min = 0;
	unsigned long long ullong_max = ULLONG_MAX;
	
	printf("printf llu:	%llu\n", ullong);
	ft_printf("my llu:		%llu\n", ullong);
	printf("printf llu:	%llu\n", ullong_min);
	ft_printf("my llu:		%llu\n", ullong_min);
	printf("printf llu:	%llu\n", ullong_max);
	ft_printf("my llu:		%llu\n\n", ullong_max);
	
	printf("printf llo:	%llo\n", ullong);
	ft_printf("my llo:		%llo\n", ullong);
	printf("printf llo:	%llo\n", ullong_min);
	ft_printf("my llo:		%llo\n", ullong_min);
	printf("printf llo:	%llo\n", ullong_max);
	ft_printf("my llo:		%llo\n\n", ullong_max);
	
	printf("printf llx:	%llx\n", ullong);
	ft_printf("my llx:		%llx\n", ullong);
	printf("printf llx:	%llx\n", ullong_min);
	ft_printf("my llx:		%llx\n", ullong_min);
	printf("printf llx:	%llx\n", ullong_max);
	ft_printf("my llx:		%llx\n\n", ullong_max);
	
	printf("printf llX:	%llX\n", ullong);
	ft_printf("my llX:		%llX\n", ullong);
	printf("printf llX:	%llX\n", ullong_min);
	ft_printf("my llX:		%llX\n", ullong_min);
	printf("printf llX:	%llX\n", ullong_max);
	ft_printf("my llX:		%llX\n\n", ullong_max);
	
	printf("\n_*UINTMAX_T*_\n\n");

	uintmax_t uintt = 424242424242;
	uintmax_t uintt_min = 0;
	uintmax_t uintt_max = UINT_MAX;
	
	printf("printf ju:	%ju\n", uintt);
	ft_printf("my ju:		%ju\n", uintt);
	printf("printf ju:	%ju\n", uintt_min);
	ft_printf("my ju:		%ju\n", uintt_min);
	printf("printf ju:	%ju\n", uintt_max);
	ft_printf("my ju:		%ju\n\n", uintt_max);
	
	printf("printf jo:	%jo\n", uintt);
	ft_printf("my jo:		%jo\n", uintt);
	printf("printf jo:	%jo\n", uintt_min);
	ft_printf("my jo:		%jo\n", uintt_min);
	printf("printf jo:	%jo\n", uintt_max);
	ft_printf("my jo:		%jo\n\n", uintt_max);
	
	printf("printf jx:	%jx\n", uintt);
	ft_printf("my jx:		%jx\n", uintt);
	printf("printf jx:	%jx\n", uintt_min);
	ft_printf("my jx:		%jx\n", uintt_min);
	printf("printf jx:	%jx\n", uintt_max);
	ft_printf("my jx:		%jx\n\n", uintt_max);
	
	printf("printf jX:	%jX\n", uintt);
	ft_printf("my jX:		%jX\n", uintt);
	printf("printf jX:	%jX\n", uintt_min);
	ft_printf("my jX:		%jX\n", uintt_min);
	printf("printf jX:	%jX\n", uintt_max);
	ft_printf("my jX:		%jX\n\n", uintt_max);
	
	printf("\n_*SIZE_T*_\n\n");

	size_t sizett = 424242424242;
	size_t sizett_min = 0;
	size_t sizett_max = UINT_MAX;
	
	printf("printf zu:	%zu\n", sizett);
	ft_printf("my zu:		%zu\n", sizett);
	printf("printf zu:	%zu\n", sizett_min);
	ft_printf("my zu:		%zu\n", sizett_min);
	printf("printf zu:	%zu\n", sizett_max);
	ft_printf("my zu:		%zu\n\n", sizett_max);
	
	printf("printf zo:	%zo\n", sizett);
	ft_printf("my zo:		%zo\n", sizett);
	printf("printf zo:	%zo\n", sizett_min);
	ft_printf("my zo:		%zo\n", sizett_min);
	printf("printf zo:	%zo\n", sizett_max);
	ft_printf("my zo:		%zo\n\n", sizett_max);
	
	printf("printf zx:	%zx\n", sizett);
	ft_printf("my zx:		%zx\n", sizett);
	printf("printf zx:	%zx\n", sizett_min);
	ft_printf("my zx:		%zx\n", sizett_min);
	printf("printf zx:	%zx\n", sizett_max);
	ft_printf("my zx:		%zx\n\n", sizett_max);
	
	printf("printf zX:	%zX\n", sizett);
	ft_printf("my zX:		%zX\n", sizett);
	printf("printf zX:	%zX\n", sizett_min);
	ft_printf("my zX:		%zX\n", sizett_min);
	printf("printf zX:	%zX\n", sizett_max);
	ft_printf("my zX:		%zX\n\n", sizett_max);

	printf("\n\n_.~***************************************************~._\n");
	printf("_.~*                    LETTERS                      *~._\n");
	printf("_.~***************************************************~._\n");

	printf("\n_*BY NUMBER*_\n\n");
	
	printf("\n_*W_INT*_\n\n");

	wchar_t *uni_str = L"☄ ★☀ ☁ ☂ ☃ 8";
	wchar_t C = uni_str[0];
	
	printf("printf C:	%C\n", C);
	ft_printf("my C:		%C\n", C);
	
	printf("\n_*W_CHAR*_\n\n");

	wchar_t *wchart = L"☄ ★☀ ☁ ☂ ☃ 8";
	
	printf("printf S:	%S\n", wchart);
	ft_printf("my S:		%S\n", wchart);
	
	printf("\n_*VOID*_\n\n");

	int ptrnum = -42;
	void *ptr = &ptrnum;
	
	printf("printf S:	%p\n", ptr);
	ft_printf("my S:		%p\n", ptr);

	printf("\n\n_.~***************************************************~._\n");
	printf("_.~*                      FLAGS                      *~._\n");
	printf("_.~***************************************************~._\n");

	printf("\n_*#*_\n\n");
	
	unsigned int flag_zero = 0;
	unsigned int flag_num = 222;
	
	printf("printf #o:	%#o\n", flag_zero);
	ft_printf("my #o:		%#o\n", flag_zero);
	printf("printf #o:	%#o\n", flag_num);
	ft_printf("my #o:		%#o\n\n", flag_num);
	
	printf("printf #x:	%#x\n", flag_zero);
	ft_printf("my #x:		%#x\n", flag_zero);
	printf("printf #x:	%#x\n", flag_num);
	ft_printf("my #x:		%#x\n\n", flag_num);
	
	printf("printf #X:	%#X\n", flag_zero);
	ft_printf("my #X:		%#X\n", flag_zero);
	printf("printf #X:	%#X\n", flag_num);
	ft_printf("my #X:		%#X\n\n", flag_num);
	
	printf("\n_*0*_\n\n");
	
	printf("printf 0o:	%05o\n", flag_zero);
	ft_printf("my 0o:		%05o\n", flag_zero);
	printf("printf 0o:	%05o\n", flag_num);
	ft_printf("my 0o:		%05o\n\n", flag_num);
	
	printf("printf 0x:	%05x\n", flag_zero);
	ft_printf("my 0x:		%05x\n", flag_zero);
	printf("printf 0x:	%05x\n", flag_num);
	ft_printf("my 0x:		%05x\n\n", flag_num);
	
	printf("printf 0X:	%05X\n", flag_zero);
	ft_printf("my 0X:		%05X\n", flag_zero);
	printf("printf 0X:	%05X\n", flag_num);
	ft_printf("my 0X:		%05X\n\n", flag_num);
	
	printf("\n_*+*_\n\n");
	
	int flag_negative = -42;

	printf("printf +d:	%+d\n", flag_zero);
	ft_printf("my +d:		%+d\n", flag_zero);
	printf("printf +d:	%+d\n", flag_negative);
	ft_printf("my +d:		%+d\n", flag_negative);
	printf("printf +d:	%+d\n", flag_num);
	ft_printf("my +d:		%+d\n\n", flag_num);
	
	printf("\n_* (SPACE)*_\n\n");

	printf("printf _d:	|% d|\n", flag_zero);
	ft_printf("my _d:		|% d|\n", flag_zero);
	printf("printf _d:	|% d|\n", flag_negative);
	ft_printf("my _d:		|% d|\n", flag_negative);
	printf("printf _d:	|% d|\n", flag_num);
	ft_printf("my _d:		|% d|\n\n", flag_num);

	printf("\n_*OTHER*_\n\n");
	
	printf("printf space D:		|% D|\n", flag_num);
	ft_printf("my space D:		|% D|\n", flag_num);
	printf("printf space O:		|%#O|\n", flag_num);
	ft_printf("my space O:		|%#O|\n", flag_num);
	printf("printf minwidth o:	|%5o|\n", flag_num);
	ft_printf("my minwidth o:		|%5o|\n", flag_num);
	printf("printf minwidth x:	|%0#10x|\n", flag_num);
	ft_printf("my minwidth x:		|%0#10x|\n", flag_num);
	printf("printf minwidth x:	|%#10x|\n", flag_num);
	ft_printf("my minwidth x:		|%#10x|\n", flag_num);
	printf("printf minwidth X:	|%5X|\n", flag_num);
	ft_printf("my minwidth X:		|%5X|\n", flag_num);
	printf("printf minwidth X:	|%5X|\n", flag_num);
	ft_printf("my minwidth X:		|%5X|\n", flag_num);
	printf("printf +.5d:		|%+.5d|\n", flag_num);
	ft_printf("my +.5d:		|%+.5d|\n", flag_num);
	printf("printf -.5d:		|%-.5d|\n", flag_num);
	ft_printf("my -.5d:		|%-.5d|\n", flag_num);
	printf("printf +5d:		|%0+10.5d|\n", flag_num);
	ft_printf("my +5d:			|%0+10.5d|\n", flag_num);
	printf("printf -5d:		|%-10.5d|\n", flag_num);
	ft_printf("my -5d:			|%-10.5d|\n", flag_num);
	
	printf("\nTEST 0049\n");
    int ret_0049 = printf("%s", "abc");
    printf("\t(%d)\n",ret_0049);
    int ret_0049F = ft_printf("%s", "abc");
    printf("\t(%d)\n",ret_0049F);
	
	printf("\nTEST 00X\n");
    int ret_00X = printf("%s", NULL);
    printf("\t(%d)\n",ret_00X);
    int ret_00XF = ft_printf("%s", NULL);
    printf("\t(%d)\n",ret_00XF);

	printf("\nTEST 0076\n");
    int ret_0076 = printf("%c", 97);
    printf("\t(%d)\n",ret_0076);
    int ret_0076F = ft_printf("%c", 97);
    printf("\t(%d)\n",ret_0076F);
	
	printf("\nTEST 0001\n");
    int ret_0001 = printf("%");
    printf("\t(%d)\n",ret_0001);
    int ret_0001F = ft_printf("%");
    printf("\t(%d)\n",ret_0001F);
	
	printf("\nTEST 0002\n");
    int ret_0002 = printf("% ");
    printf("\t(%d)\n",ret_0002);
    int ret_0002F = ft_printf("% ");
    printf("\t(%d)\n",ret_0002F);
	
	printf("\nTEST 000Y\n");
    int ret_000Y = printf("%%");
    printf("\t(%d)\n",ret_000Y);
    int ret_000YF = ft_printf("%%");
    printf("\t(%d)\n",ret_000YF);
	
	printf("\nTEST 0003\n");
    int ret_0003 = printf("% h");
    printf("\t(%d)\n",ret_0003);
    int ret_0003F = ft_printf("% h");
    printf("\t(%d)\n",ret_0003F);
	
	printf("\nTEST 0004\n");
    int ret_0004 = printf("%Z");
    printf("\t(%d)\n",ret_0004);
    int ret_0004F = ft_printf("%Z");
    printf("\t(%d)\n",ret_0004F);

	printf("\nTEST 0014\n");
    int ret_0014 = printf("%%   %", "test");
    printf("\t(%d)\n",ret_0014);
    int ret_0014F = ft_printf("%%   %", "test");
    printf("\t(%d)\n",ret_0014F);
	
	printf("\nTEST 00A\n");
    int ret_00A = printf("%#o", 0);
    printf("\t(%d)\n",ret_00A);
    int ret_00AF = ft_printf("%#o", 0);
    printf("\t(%d)\n",ret_00AF);
	
	printf("\nTEST 00P\n");
    int ret_00P = printf("%p", 0);
    printf("\t(%d)\n",ret_00P);
    int ret_00PF = ft_printf("%p", 0);
    printf("\t(%d)\n",ret_00PF);
	
}
