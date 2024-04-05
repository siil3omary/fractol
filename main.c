#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	exit(EXIT_FAILURE);
}

int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
	{
		return (1);
	}
	return (0);
}
double	ft_atod(char *str)
{
	double	result;
	double	part;
	double	sign;
	int		i;
	double	place;

	result = 0.0;
	part = 0.0;
	sign = 1;
	i = 0;
	place = 0.1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && str[i] != '.' && ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		part = part + (str[i] - '0') * place;
		place /= 10;
		i++;
	}
	result += part;
	return (sign * result);
}
int	main(int ac, char **av)
{
	printf("%f\n%f", ft_atod(av[1]), ft_atod(av[2]));
	return (0);
}
