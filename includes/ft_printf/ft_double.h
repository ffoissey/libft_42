/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:08:52 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/26 10:08:54 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOUBLE_H
# define FT_DOUBLE_H

# include "ft_printf.h"
# define P0  "10000000000000000000000000000000000000000000000000000000000000000"
# define P1  "05000000000000000000000000000000000000000000000000000000000000000"
# define P2  "02500000000000000000000000000000000000000000000000000000000000000"
# define P3  "01250000000000000000000000000000000000000000000000000000000000000"
# define P4  "00625000000000000000000000000000000000000000000000000000000000000"
# define P5  "00312500000000000000000000000000000000000000000000000000000000000"
# define P6  "00156250000000000000000000000000000000000000000000000000000000000"
# define P7  "00078125000000000000000000000000000000000000000000000000000000000"
# define P8  "00039062500000000000000000000000000000000000000000000000000000000"
# define P9  "00019531250000000000000000000000000000000000000000000000000000000"
# define P10 "00009765625000000000000000000000000000000000000000000000000000000"
# define P11 "00004882812500000000000000000000000000000000000000000000000000000"
# define P12 "00002441406250000000000000000000000000000000000000000000000000000"
# define P13 "00001220703125000000000000000000000000000000000000000000000000000"
# define P14 "00000610351562500000000000000000000000000000000000000000000000000"
# define P15 "00000305175781250000000000000000000000000000000000000000000000000"
# define P16 "00000152587890625000000000000000000000000000000000000000000000000"
# define P17 "00000076293945312500000000000000000000000000000000000000000000000"
# define P18 "00000038146972656250000000000000000000000000000000000000000000000"
# define P19 "00000019073486328125000000000000000000000000000000000000000000000"
# define P20 "00000009536743164062500000000000000000000000000000000000000000000"
# define P21 "00000004768371582031250000000000000000000000000000000000000000000"
# define P22 "00000002384185791015625000000000000000000000000000000000000000000"
# define P23 "00000001192092895507812500000000000000000000000000000000000000000"
# define P24 "00000000596046447753906250000000000000000000000000000000000000000"
# define P25 "00000000298023223876953125000000000000000000000000000000000000000"
# define P26 "00000000149011611938476562500000000000000000000000000000000000000"
# define P27 "00000000074505805969238281250000000000000000000000000000000000000"
# define P28 "00000000037252902984619140625000000000000000000000000000000000000"
# define P29 "00000000018626451492309570312500000000000000000000000000000000000"
# define P30 "00000000009313225746154785156250000000000000000000000000000000000"
# define P31 "00000000004656612873077392578125000000000000000000000000000000000"
# define P32 "00000000002328306436538696289062500000000000000000000000000000000"
# define P33 "00000000001164153218269348144531250000000000000000000000000000000"
# define P34 "00000000000582076609134674072265625000000000000000000000000000000"
# define P35 "00000000000291038304567337036132812500000000000000000000000000000"
# define P36 "00000000000145519152283668518066406250000000000000000000000000000"
# define P37 "00000000000072759576141834259033203125000000000000000000000000000"
# define P38 "00000000000036379788070917129516601562500000000000000000000000000"
# define P39 "00000000000018189894035458564758300781250000000000000000000000000"
# define P40 "00000000000009094947017729282379150390625000000000000000000000000"
# define P41 "00000000000004547473508864641189575195312500000000000000000000000"
# define P42 "00000000000002273736754432320594787597656250000000000000000000000"
# define P43 "00000000000001136868377216160297393798828125000000000000000000000"
# define P44 "00000000000000568434188608080148696899414062500000000000000000000"
# define P45 "00000000000000284217094304040074348449707031250000000000000000000"
# define P46 "00000000000000142108547152020037174224853515625000000000000000000"
# define P47 "00000000000000071054273576010018587112426757812500000000000000000"
# define P48 "00000000000000035527136788005009293556213378906250000000000000000"
# define P49 "00000000000000017763568394002504646778106689453125000000000000000"
# define P50 "00000000000000008881784197001252323389053344726562500000000000000"
# define P51 "00000000000000004440892098500626161694526672363281250000000000000"
# define P52 "00000000000000002220446049250313080847263336181640625000000000000"
# define P53 "00000000000000001110223024625156540423631668090820312500000000000"
# define P54 "00000000000000000555111512312578270211815834045410156250000000000"
# define P55 "00000000000000000277555756156289135105907917022705078125000000000"
# define P56 "00000000000000000138777878078144567552953958511352539062500000000"
# define P57 "00000000000000000069388939039072283776476979255676269531250000000"
# define P58 "00000000000000000034694469519536141888238489627838134765625000000"
# define P59 "00000000000000000017347234759768070944119244813919067382812500000"
# define P60 "00000000000000000008673617379884035472059622406959533691406250000"
# define P61 "00000000000000000004336808689942017736029811203479766845703125000"
# define P62 "00000000000000000002168404344971008868014905601739883422851562500"
# define P63 "00000000000000000001084202172485504434007452800869941711425781250"
# define P64 "00000000000000000000542101086242752217003726400434970855712890625"
# define LONG_DOUBLE 64

void		ft_dup(char **src, char *s);
char		*ft_set_mantisse(int *tab, int size);
char		*ft_get_int(int *tab, int size, int max);
char		*ft_addition(char *m, char *s);
char		*ft_power_of_two(char *s);
void		ft_fill_with_zero(char *s, int size);
void		ft_str_rev_cpy(char *dest, char *src);
int			ft_check_zero_mantissa(int *tab);
void		ft_get_prec(char **exp, int prec);
char		*ft_zero(void *ptr);
void		ft_set_ptr(void	*ptr, int *tab);
void		ft_mantisse(int *m, int *tab, int size);
void		ft_sign_and_exp(int *m, int *exp_pow);

#endif
