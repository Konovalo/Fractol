unsigned long int		ft_lpow(int nbr, int k)
{
	int					i;
	unsigned long int	n;

	n = 1;
	i = 0;
	while (i < k)
	{
		n = n * nbr;
		i++;
	}
	return (n);
}
