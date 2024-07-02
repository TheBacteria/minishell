#include <stdio.h>

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int mz_get_key()
{
    int random;
    int key;
	int result;
	random = open("/dev/urandom", O_RDONLY);
    if (random < 0)
        return (0);
    result = read(random, &key, sizeof(key));
    if (result < 0)
    {
		close(random);
		return (0);
	}
    close(random);
    return (key);
}

int main(void)
{
    int i;
    i = mz_get_key();
    // if(i < 0)
    //     i = i * -1;

    printf("%d\n", i);
    return (0);
}