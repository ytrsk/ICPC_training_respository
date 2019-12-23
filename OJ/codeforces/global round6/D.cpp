create table course_choose
(
   student_id varchar(20),
   course_id  varchar(20),
   primary key (student_id, course_id)
   foreign key (student_id) references student(student_id),
   foreign key (course_id) references course(course_id)
);

alter table course_choose add constraint FK_COURSE_C_COURSE_CH_STUDENT foreign key (student_id)
      references student (student_id) on delete restrict on update restrict;

alter table course_choose add constraint FK_COURSE_C_COURSE_CH_COURSE foreign key (course_id)
      references course (course_id) on delete restrict on update restrict;
