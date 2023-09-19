#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define SIZE 100000
#define COMPARE(m,k) (((m) < (k)) ? -1 : ((m) == (k)) ? 0 : 1))
#pragma warning(disable:4996)

void Sort(int list[], int n) {// �����Լ�
	int min, temp;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);

	}
}

int is_Sorted(int list[], int n) {//����Ȯ�� �Լ�
	int isTrue = 1; //������ �ùٸ��� 1 �߸���ٸ� 0
	for (int i = 0; i < n - 1; i++) {
		if (list[i] > list[i + 1]) {
			isTrue = 0;
			break;
		}
	}
	if (isTrue == 1)
		return 1;
	else return 0;
}

int bin_Search(int list[], int key, int left, int right, int* counter) { //�����˻� �Լ�
	int middle;
	*counter = 0;
	while (left <= right) {
		*counter += 1;
		middle = (left + right) / 2;
		switch (COMPARE(list[middle], key) {
		case -1: left = middle + 1; break;
		case 0: return middle;
		case 1: right = middle - 1;
		}
	}
	return -1;
}

int main() {
	printf("1.1	\n100,000������ ������ ���� ������\n");
	int A[SIZE];//�迭����
	for (int i = 0; i < SIZE; i++) { //�迭�� �� �ֱ�
		A[i] = (rand() % SIZE) + 1;
		printf("%d  ", A[i]);
	}
	printf("\n�������� �Ϸ�\n�������� ����\n");
	Sort(A, SIZE); //���Ľ���
	for (int i = 0; i < SIZE; i++)
		printf("%d  ", A[i]);
	printf("\n���ĿϷ� \n����Ȯ�� ����\n");
	if (is_Sorted(A, SIZE) == 1) //����Ȯ��
		printf("������ �ùٸ��ϴ�.");
	else printf("������ �ùٸ��� �ʽ��ϴ�.");

	//1.2 ����
	printf("\n1.2\n �迭�� ũ�⸦ �����Ͻÿ�.(����� -1)\n");
	static int B[1000000]; int size2; //�ι�° �迭
	while (1) {	//�迭 �ݺ�����
		scanf("%d", &size2);
		if (size2 == -1) { printf("�迭������ �����մϴ�.\n"); break; }
		else for (int i = size2; i > 0; i--) {
			B[i - 1] = i;
		}
		double time = 0.0; //�ð������ ���� �ɸ��ð� ����
		clock_t start = clock();
		Sort(B, size2); //�������� ����
		clock_t end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		char is_Clear[10] = "���ĵ�";
		if (is_Sorted(B, size2) == 1) { //���
			printf("ũ��: %d		�ð�: %f		����: %s\n", size2, time, is_Clear);
		}
		else printf("���ĵ�������");
	}

	//1.3
	printf("1.3");
	int key, left = 0, right = SIZE - 1, counter;
	while (1) {
		printf("\n�˻��� �Է�(����:1~100000, ����: -1): ");
		scanf("%d", &key);
		if (key == -1) break;
		bin_Search(A, key, left, right, &counter);
		if (bin_Search(A, key, left, right, &counter) != -1) {
			printf("�˻���: %d  Counter: %d:\n", key, counter);
		}
		else {
			printf("�˻���: %d  Counter: -1:\n", key);
		}
	}

	//1.4
	printf("1.4 �迭���� �� ������\n");
	int c_size = 50000, d_size = 100000;
	int C[50000], D[100000];
	for (int i = c_size; i > 0; i--) {
		C[i - 1] = i;
	}
	for (int i = d_size; i > 0; i--) {
		D[i - 1] = i;
	}
	Sort(C, c_size); Sort(D, d_size);
	is_Sorted(C, c_size); is_Sorted(D, d_size);

	if (is_Sorted(C, c_size) == 1) //C ����Ȯ��
		printf("C�� ������ �ùٸ��ϴ�.\n");
	else printf("C�� ������ �ùٸ��� �ʽ��ϴ�.\n");

	if (is_Sorted(D, d_size) == 1) //D����Ȯ��
		printf("D�� ������ �ùٸ��ϴ�.");
	else printf("D�� ������ �ùٸ��� �ʽ��ϴ�.");

	//C�迭 �˻�
	int key_c, left_c = 0, right_c = c_size - 1, counter_c;
	while (1) {
		printf("\nC�迭 �˻��� �Է�(����:1~50000, ����: -1): ");
		scanf("%d", &key_c);
		if (key_c == -1) break;
		bin_Search(C, key_c, left_c, right_c, &counter_c);
		if (bin_Search(C, key_c, left_c, right_c, &counter_c) != -1) {
			printf("�˻���: %d  Counter: %d:\n", key_c, counter_c);
		}
		else {
			printf("�˻���: %d  Counter: -1:\n", key_c);
		}
	}
	//D�迭 �˻�
	int key_d, left_d = 0, right_d = d_size - 1, counter_d;
	while (1) {
		printf("\nD�迭 �˻��� �Է�(����:1~100000, ����: -1): ");
		scanf("%d", &key_d);
		if (key_d == -1) break;
		bin_Search(D, key_d, left_d, right_d, &counter_d);
		if (bin_Search(D, key_d, left_d, right_d, &counter_d) != -1) {
			printf("�˻���: %d  Counter: %d:\n", key_d, counter_d);
		}
		else {
			printf("�˻���: %d  Counter: -1:\n", key_d);
		}
	}
	printf("�������� ����Ǿ����ϴ�.");
}