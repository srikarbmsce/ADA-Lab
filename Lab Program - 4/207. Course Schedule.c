bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {

    int indegree[numCourses];
    for(int i = 0; i < numCourses; i++)
        indegree[i] = 0;

    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* size = (int*)calloc(numCourses, sizeof(int));

    for(int i = 0; i < numCourses; i++)
        graph[i] = (int*)malloc(numCourses * sizeof(int));

    for(int i = 0; i < prerequisitesSize; i++){
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        graph[b][size[b]++] = a;
        indegree[a]++;
    }

    int queue[numCourses];
    int front = 0, rear = 0;

    for(int i = 0; i < numCourses; i++){
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while(front < rear){
        int course = queue[front++];
        count++;

        for(int i = 0; i < size[course]; i++){
            int next = graph[course][i];
            indegree[next]--;

            if(indegree[next] == 0)
                queue[rear++] = next;
        }
    }

    return count == numCourses;
}
