#include<stdio.h>
#include "include/libft/libft.h"

typedef enum e_bool
{
	__FALSE = -999999,
	__TRUE = -111111
}				t_bool;

void	ft_freesplit(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}
int	ft_lensplit(char **sstr)
{
	int	i;

	i = 0;
	if (!sstr)
		return (0);
	while (sstr[i])
		i++;
	return (i);
}

t_bool	ft_contain_num(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (__FALSE);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (__TRUE);
		i++;
	}
	return (__FALSE);
}

t_bool	ft_cpy_fill(char **dest, char **src, char *num)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		dest[i] = ft_strdup(src[i]);
		if (!dest[i])
			return (__FALSE);
		i++;
	}
	dest[i] = ft_strdup(num);
	if (!dest[i])
		return (__FALSE);
	dest[i + 1] = NULL;
	return (__TRUE);
}

char	**ft_add_num(char **sstr, char *num)
{
	char	**new;
	int		len;
	t_bool	fdbk;

	new = NULL;
	fdbk = __TRUE;
	len = ft_lensplit(sstr);
	new = ft_calloc(len + 2, sizeof(char *));
	if (!new)
		fdbk = __FALSE;
	if (fdbk == __TRUE)
		fdbk = ft_cpy_fill(new, sstr, num);
	if (fdbk == __FALSE)
	{
		ft_freesplit(new);
		ft_freesplit(sstr);
		return (NULL);
	}
	ft_freesplit(sstr);
	sstr = new;
	return (new);
}

char	**ft_keepnum(char **data)
{
	char	**newdata;
	int		i;

	i = 0;
	newdata = NULL;
	if (!data)
		return (NULL);
	while (data[i])
	{
		if (ft_contain_num(data[i]) == __TRUE)
		{
			newdata = ft_add_num(newdata, data[i]);
			if (!newdata)
			{
				ft_freesplit(newdata);
				ft_freesplit(data);
				return (NULL);
			}
		}
		i++;
	}
	ft_freesplit(data);
	return (newdata);
}

int main()
{
	int	i;
	char	**sstr;
	
	i = 0;
	sstr = ft_split(" -7 9 4 0 1 0 0 -1 -1 0 2 1 0 0  \n  - \n", ' ');
	sstr = ft_keepnum(sstr);
	if (!sstr)
	{
		printf ("error ft_keepnum() failed!!\n");
		ft_freesplit(sstr);
		return (0);
	}
	while (sstr[i])
	{
		printf("%s\n", sstr[i]);
		i++;
	}
	printf("len: %d\n", i);
	ft_freesplit(sstr);
	return 0;
}
