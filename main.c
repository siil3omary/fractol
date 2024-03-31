#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_isdigit(char c)
{
	printf("%c", c);
	if (c >= '0' && c <= '9')
		return (1);
	printf("e");
	exit(EXIT_FAILURE);
}

double	ft_atod(char *str)
{
	double	result;
	double	part;
	double	sign;
	int		i;
	double	place;

	i = 0;
	part = 0.0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i] == '-')
			sign = -1;
	if (!str[i])
		exit(1);
	while (str[i] && str[i] != '.' && ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i++] == '\0')
		exit(EXIT_FAILURE);
	place = 0.1;
	while (str[i] && ft_isdigit(str[i]))
	{
		part += (str[i] - '0') * place;
		place /= 10;
		i++;
	}
	result += part;
	return (sign * (result + part));
}
int	main(int ac, char **av)
{
	printf("%f", ft_atod("55.45"));
	return (0);
}
