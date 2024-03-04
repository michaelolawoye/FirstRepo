    for (int i = 0; i < NAME_COUNT; i++) {
        if (fgets(names[i], MAX_LEN, stdin)[0] != '\n') {
            printf("the name entered was: %s", names[i]);
        }
    }
    printf("Names inputted:");
    for (int i = 0; i < NAME_COUNT; i++) {
        printf("%s\n", names[i]);
    }