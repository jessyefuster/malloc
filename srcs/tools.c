// static int	ft_len_num_unsigned(unsigned long long value, int base)
// {
// 	int		len;

// 	len = 0;
// 	while (value / base > 0)
// 	{
// 		value /= base;
// 		len++;
// 	}
// 	return (len + 1);
// }

// char		*ft_utob(unsigned long long value, int base, char *base_str)
// {
// 	char	*str;
// 	int		len;

// 	len = ft_len_num_unsigned(value, base);
// 	str = (char *)malloc(sizeof(char) * (len + 1));
// 	str[len] = '\0';
// 	len--;
// 	while (len >= 0)
// 	{
// 		str[len] = base_str[value % base];
// 		value /= base;
// 		len--;
// 	}
// 	return (str);
// }

// void	put_adress(uintptr_t value)
// {
// 	char		*str;

// 	str = utob(value, 16, "0123456789abcdef");
// 	write(1, "0x", 2);
// 	write(1, str, strlen(str));
// }