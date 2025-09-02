
char    *get_line(char *stash);

char    *get_next_line(int fd)
{
    static char    stash[BUFFER_SIZE + 1];
    char           buff[BUFFER_SIZE + 1];
    char           *tmp;
    char           *line;
    ssize_t        bytes;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    bytes = 1;
    while (!ft_strchr(stash, '\n') && bytes > 0)
    {
        bytes = read(fd, buff, BUFFER_SIZE);
        if (bytes < 0)
            return (NULL);
        buff[bytes] = '\0';
        if (!(tmp = ft_strjoin(stash, buff)))
            return (NULL);
        ft_strlcpy(stash, tmp, BUFFER_SIZE + 1);
        free(tmp);
    }
    if (stash[0] == '\0')
        return (NULL);
    return (get_line(stash));
}
char    *get_line(char *stash)
{
    char    *line;
    char    *newstash;
    int     nl;

    nl = ft_strchr(stash, '\n');
    if (nl < 0)
    {
        line = ft_strdup(stash);
        stash[0] = '\0';
        return (line);
    }
    if (!(line = ft_substr(stash, 0, nl + 1)))
        return (NULL);
    if (!(newstash = ft_substr(stash,
                nl + 1,
                ft_strlen(stash) - nl - 1)))
    {
        free(line);
        return (NULL);
    }
    ft_strlcpy(stash, newstash, BUFFER_SIZE + 1);
    free(newstash);
    return (line);
}