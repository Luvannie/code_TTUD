#include<stdio.h>
 
void init();
void readInput();
void handle();
void tryAssigned(int );
bool checkConditionAssigned(int , int );
 
bool checkConflic(int , int );
void updateMinMaxLoad();
 
const int MAX_COURSE = 36;
const int MAX_TEACHER = 16;
const bool CONFLIC = true;
const bool TEACH = true;
 
// contain courses conflic with this course
// chua nhung khoa hoc ma conflic no
// nhung khoa hoc ma no conflic se duoc danh dau la true
struct Conflic {
	
	bool confWiths[MAX_COURSE];
};
 
// chua nhung khoa hoc nam trong danh sach chuyen mon cua giao vien
// nhung khoa hoc ma giao dien day se duoc danh dau la true
struct Teacher {
	
	bool courses[MAX_COURSE];
};
 
// chua nhung khoa hoc ma giao vien duoc phan
struct TeacherAssigned {
	
	int courseAssigned [MAX_COURSE];
	int numCourseAssigned;
};
 
int totalCourse;
int totalTeacher;
int numPairCourseConf;
Conflic confs[MAX_COURSE];
Teacher teachers[MAX_TEACHER];
TeacherAssigned teacherAssigneds[MAX_TEACHER];
 
int minOfMaxLoad;
 
int tempMaxLoad;
 
 
/////////////////////////////
int main() {
	
	handle();
	return 0;
}
 
 
void init() {
	
	tempMaxLoad = 0;
	minOfMaxLoad = MAX_COURSE;
	for (int i = 1; i < MAX_COURSE; i++) {
	
		teacherAssigneds[i].numCourseAssigned = 0;
		for (int j = 1; j < MAX_COURSE; j++) {
			confs[i].confWiths[j] = false;
		}
	}
	
	for (int i = 1; i < MAX_TEACHER; i++) {
		for (int j = 1; j < MAX_COURSE; j++) {
			teachers[i].courses[j] = false;
		}
	}
}
 
void readInput() {
	
//	FILE * f = fopen("in2.txt", "rt");
//	fscanf(f, "%d", &totalTeacher);
//	fscanf(f, "%d", &totalCourse);
	scanf( "%d", &totalTeacher);
	scanf( "%d", &totalCourse);
	int numCourseOfTeacher;
	int course;
 
	for (int i = 1; i <= totalTeacher; i++) {
		
//		fscanf(f, "%d", &numCourseOfTeacher);
		scanf("%d", &numCourseOfTeacher);
		for (int j = 1; j <= numCourseOfTeacher; j++) {
			
//			fscanf(f, "%d", &course);
			scanf("%d", &course);
			teachers[i].courses[course] = TEACH;
		}
	}
	
//	fscanf(f, "%d", &numPairCourseConf);
	scanf("%d", &numPairCourseConf);
	int firstCourse;
	int secondCourse;
	for (int i = 1; i <= numPairCourseConf; i++) {
		
//		fscanf(f, "%d %d", &firstCourse, &secondCourse);
		scanf("%d %d", &firstCourse, &secondCourse);
		confs[firstCourse].confWiths[secondCourse] = CONFLIC;
		confs[secondCourse].confWiths[firstCourse] = CONFLIC;
	}
	
//	fclose(f);
} 
 
void handle() {
	
	init();
	readInput();
	tryAssigned(1);
	if (minOfMaxLoad == MAX_COURSE) {
		minOfMaxLoad = -1;
	}
	printf("%d", minOfMaxLoad);
	
}
 
void tryAssigned(int j) {
	
	int preTempMaxLoad = tempMaxLoad;
	for (int i = 1; i <= totalTeacher; i++) {
		
		if (checkConditionAssigned(i, j)) {
	
			teacherAssigneds[i].courseAssigned[teacherAssigneds[i].numCourseAssigned] = j;
			teacherAssigneds[i].numCourseAssigned ++;
			if (teacherAssigneds[i].numCourseAssigned > tempMaxLoad) {
				tempMaxLoad = teacherAssigneds[i].numCourseAssigned;
			}
			
			if (j == totalCourse) {
				
				// do something
				if (tempMaxLoad != 0 && tempMaxLoad < minOfMaxLoad) {
					minOfMaxLoad = tempMaxLoad;
				}
		
			} else if (tempMaxLoad <= minOfMaxLoad){
				
				tryAssigned(j + 1);
			}
			teacherAssigneds[i].numCourseAssigned --;
			tempMaxLoad = preTempMaxLoad;
		}
	}
	
}
 
 
bool checkConditionAssigned(int teacher, int course) {
	
	if (teachers[teacher].courses[course]) {
		
		return checkConflic(teacher, course);
	}
	return false;
}
 
 
// kiem tra khoa hoc nay co xung dot voi cac
// khoa hoc truoc do cua teacher nay hay khong
bool checkConflic(int teacher, int course) {
	
	int * courseAssigneds = teacherAssigneds[teacher].courseAssigned;
	int numAssigned = teacherAssigneds[teacher].numCourseAssigned;
	bool * confWiths = confs[course].confWiths;
	
	for (int j = 0; j < numAssigned; j++) {
		if (confWiths[courseAssigneds[j]] == CONFLIC) {
			return false;
		}
	}
	
	return true;
}
 
void updateMinMaxLoad() {
	
	if (tempMaxLoad != 0 && tempMaxLoad < minOfMaxLoad) {
		minOfMaxLoad = tempMaxLoad;
	}
	
}
