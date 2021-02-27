int		ft_slova(char const *s, char c)
{
	int	i;
	int	sl;

	i = 0;
	sl = 0;
	while (s[i] != '\0')
	{
		if (s[i + 1] != '\0' && s[i] != c && s[i + 1] == c)
			sl++;
		i++;
	}
	if (s[i - 1] != c)
		sl++;
	return (sl);
}
