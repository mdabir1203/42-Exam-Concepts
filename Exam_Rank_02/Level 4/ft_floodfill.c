/**
 * Reallife Analogy:
There is a map with different areas. 
To mark an area that has the same name as where they start.
They use a pen to make a line around the area.
The flood_fill function is like using the pen on the area
they start from (begin).
The fill function is like looking at the areas next to the current area (cur)
and making a line around them if they have the same name
as the first area (to_fill).
The fill function also does this again and again 
for each area with a line around it, 
until there are no more areas with the same name.
The (size) parameter is like the size of the map,
i.e. stops them from going outside the map.
**/

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
