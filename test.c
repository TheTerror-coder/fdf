#include<stdio.h>
#include "include/libft/libft.h"


typedef struct	s_coord
{
	double	x;
	double	y;
	double	z;
}				t_coord;

typedef struct	s_vec
{
	t_coord	*o;
	t_coord *e;
}				t_vec;

void	ft_free_vect(t_vec *vec, t_coord *o, t_coord *e)
{
	if (o)
		free(o);
	if (e)
		free(e);
	if (vec)
		free(vec);
	o = NULL;
	e = NULL;
	vec = NULL;
}

t_vec	*ft_alloc_vect(unsigned int nmemb, unsigned int size)
{
	t_vec	*vec;
	t_coord	*o;
	t_coord	*e;

	o = NULL;
	e = NULL;
	vec = NULL;
	o = ft_calloc(1, sizeof(t_coord));
	e = ft_calloc(1, sizeof(t_coord));
	vec = ft_calloc(nmemb, size);
	if (!o || !e || !vec)
	{
		ft_free_vect(vec, o, e);
		return (NULL);
	}
	vec->o = o;
	vec->e = e;
	return (vec);
}

void	ft_free_listvec(t_vec **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		ft_free_vect(list[i], list[i]->o, list[i]->e);
		i++;
	}
	free(list);
	list = NULL;
}

t_vec	**ft_alloclist_vec(unsigned int nmemb, unsigned int size)
{
	unsigned int		i;
	t_vec	**list;
	t_vec	*vec;

	i = 0;
	list = NULL;
	vec = NULL;
	list = ft_calloc(nmemb, size);
	if (!list)
		return (NULL);
	while (i < nmemb - 1)
	{
		vec = ft_alloc_vect(1, sizeof(t_vec));
		if (!vec)
		{
			list[i] = NULL;
			ft_free_listvec(list);
			return (NULL);
		}
		list[i] = vec;
		i++;
	}
	list[i] = NULL;
	return (list);
}

int main()
{
	int	i;
	t_vec	**vec;

	i = 0;
	vec = ft_alloclist_vec(3, sizeof(t_vec *));
	if (!vec)
	{
		printf("Error Alloc failed!!\n");
		return (0);
	}
	vec[0]->o->x  = 0;
	vec[0]->o->y  = 0;
	vec[0]->o->z  = 0;
	vec[0]->e->x  = 2;
	vec[0]->e->y  = 2;
	vec[0]->e->z  = 2;
	vec[1]->o->x  = 4;
	vec[1]->o->y  = 4;
	vec[1]->o->z  = 4;
	vec[1]->e->x  = 3;
	vec[1]->e->y  = 3;
	vec[1]->e->z  = 3;

	while (vec[i])
	{
		printf("x: %f\n", vec[i]->o->x);
		printf("y: %f\n", vec[i]->o->y);
		printf("z: %f\n", vec[i]->o->z);
		printf("x: %f\n", vec[i]->e->x);
		printf("y: %f\n", vec[i]->e->y);
		printf("z: %f\n", vec[i]->e->z);
		i++;
	}
	ft_free_listvec(vec);
	return 0;
}
