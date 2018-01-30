from django.shortcuts import render
from .models import Lectures, Professors, Departments, Students, Majors, Ratings
from django.contrib.auth.models import User
from django.contrib.auth import authenticate, login, logout


def mainpage(request):
	return render(request, 'mainpage/mainpage.html')

<<<<<<< HEAD
def goto_login(request):
	return render(request, 'registeration/logintemplate.html')

def goto_signup(request):
	return render(request, 'registeration/signuptemplate.html')

=======

def goto_login(request):
	return render(request, 'registeration/logintemplate.html')


def goto_signup(request):
	return render(request, 'registeration/signuptemplate.html')


>>>>>>> 63093545243e506b2eb788f2aeee4ca4d2dcd395
def make_login(request):
	user_id = request.POST.get('login_id_box', None)
	user_pw = request.POST.get('login_pw_box', None)
	user = authenticate(username=user_id, password=user_pw)
	if user is not None:
		login(request, user)
		return render(request, 'mainpage/mainpage.html')
	else:
		context = {'is_incorrect': True}
		return render(request, 'registeration/logintemplate.html', context)

<<<<<<< HEAD
=======

>>>>>>> 63093545243e506b2eb788f2aeee4ca4d2dcd395
def make_signup(request):
	user_id = request.POST.get('username_box', None)
	pw = request.POST.get('pw_box', None)
	email = request.POST.get('email_box', None)
	sid = request.POST.get('sid_box', None)
	dept = request.POST.get('dept_box', None)
	major = request.POST.get('major_box', None)
	year = request.POST.get('year_box', None)
	if dept == "0" or major == "0":  # 부서 또는 전공이 입력되지 않은 경우
		return render(request, 'registeration/signuptemplate.html', {'is_incorrect': True, 'empty_slot': True})
	user = User.objects.filter(username=user_id)
	if len(user) == 1:  # 이미 아이디가 존재하는 경우
		return render(request, 'registeration/signuptemplate.html', {'is_incorrect': True, 'already_id': True})
	stu = Students.objects.filter(s_id=sid)
	if len(stu) == 1:  # 이미 학번(s_id)이 존재하는 경우
		return render(request, 'registeration/signuptemplate.html', {'is_incorrect': True, 'already_sid': True})

	m_obj = Majors.objects.filter(m_name=major)
	d_obj = Departments.objects.filter(d_name=dept)

	Students(s_id=sid, s_d=d_obj[0], s_m=m_obj[0], username=user_id, s_email=email, since_y=int(year)).save()
	User.objects.create_user(username=user_id, email=email, password=pw)
	return render(request, 'mainpage/mainpage.html')

<<<<<<< HEAD
=======

>>>>>>> 63093545243e506b2eb788f2aeee4ca4d2dcd395
def make_logout(request):
	logout(request)
	return render(request, 'mainpage/mainpage.html')

<<<<<<< HEAD
=======

>>>>>>> 63093545243e506b2eb788f2aeee4ca4d2dcd395
def search_lecture(request):
	returns = []
	# names = []
	l_name = request.GET.get('search_lecture_box', None)
	l_obj = Lectures.objects.filter(l_name__contains=l_name).order_by('l_name')

	for each in l_obj:
		temp_p_obj = Professors.objects.get(pk=each.l_p_id)
		p_obj = Professors.objects.get(pk=temp_p_obj.p_id)
		name = None
		if p_obj.have_kname == "Y":  # 한국이름
			name = p_obj.p_l_name + p_obj.p_f_name
		else:  # 영어이름
			name = p_obj.p_f_name + " " + p_obj.p_l_name
		returns.append([each, p_obj, each.l_id[0:len(each.l_id) - 7], name])

	return render(request, 'mainpage/search_l_result.html', {'returns': returns})

<<<<<<< HEAD
=======

>>>>>>> 63093545243e506b2eb788f2aeee4ca4d2dcd395
def search_professor(request):
	profs = []
	p_name = request.GET.get('search_professor_box', None)

	all_prof_names = []
	professors = Professors.objects.all()
	for each in professors:
		all_prof_names.append([each.p_l_name + each.p_f_name, each])
	for i in range(len(all_prof_names)):
		if p_name in all_prof_names[i][0]:
			prof_obj = all_prof_names[i][1]
			# 한국어 이름
			if prof_obj.have_kname == "Y":
				t_name = prof_obj.p_l_name + prof_obj.p_f_name
			# 영어 이름
			else:
				t_name = prof_obj.p_f_name + " " + prof_obj.p_l_name
			profs.append([prof_obj, t_name, Departments.objects.get(pk=prof_obj.p_d_id).d_name])
	# 검색 결과 없음
	if len(profs) == 0:
		return render(request, 'mainpage/search_p_result.html')
	else:
		return render(request, 'mainpage/search_p_result.html', {'profs': profs})

<<<<<<< HEAD
=======

>>>>>>> 63093545243e506b2eb788f2aeee4ca4d2dcd395
def cal_rating(ratings):
	if not ratings:
		return None
	lec_sum = 0
	hw_sum = 0
	exam_sum = 0
	quiz_sum = 0
	att_sum = 0
	avg_sum = 0
	comments = []
	num_ratings = ratings.count()
	for each in ratings:
		lec_sum += each.lec_rating
		hw_sum += each.hw_rating
		quiz_sum += each.quiz_rating
		att_sum += each.att_rating
		exam_sum += each.exam_rating
		avg_sum += each.avg_rating
		comments.append(each.comment)
	return [round(exam_sum / num_ratings, 2), round(quiz_sum / num_ratings, 2), round(hw_sum / num_ratings, 2), \
			round(att_sum / num_ratings, 2), round(lec_sum / num_ratings, 2), round(avg_sum / num_ratings, 2)], comments

<<<<<<< HEAD
=======

>>>>>>> 63093545243e506b2eb788f2aeee4ca4d2dcd395
def detail(request, pk):
	lecture = Lectures.objects.get(pk=pk)
	lecture_id = lecture.l_id[0:(len(lecture.l_id) - 7)]
	p_id = lecture.l_p_id
	prof = Professors.objects.get(pk=p_id)
	p_name = None
	if prof.have_kname == "Y":  # 한국어 이름인 경우
		p_name = prof.p_l_name + prof.p_f_name
	else:  # 영어 이름인 경우
		p_name = prof.p_f_name + " " + prof.p_l_name
	ratings = Ratings.objects.filter(r_l=pk)
	if len(ratings) == 0:  # 평가가 없을때
		return render(request, 'detail/lecture_detail.html', {'lecture': lecture, 'lecture_id': lecture_id, \
															  'p_name': p_name})
	else:  # 기존의 평가가 존재할 때
		avg_rating, comments = cal_rating(ratings)
		return render(request, 'detail/lecture_detail.html', {'lecture': lecture, 'lecture_id': lecture_id, \
															  'avg_rating': avg_rating, 'comments': comments,
															  'prof': prof, 'p_name': p_name})

<<<<<<< HEAD
=======

>>>>>>> 63093545243e506b2eb788f2aeee4ca4d2dcd395
def goto_rate(request, pk):
	lecture = Lectures.objects.get(pk=pk)
	lec_ratings = Ratings.objects.filter(r_l_id=pk)
	username = request.user.username
	stu_by_fil = Students.objects.filter(username=username)
	for each in lec_ratings:
		if each.r_s_id == stu_by_fil[0].s_id:  # 평가한 적 있음
			return detail(request, pk)
	# 평가한 적 없음
	return render(request, 'detail/rate.html', {'lecture': lecture})

<<<<<<< HEAD
=======

>>>>>>> 63093545243e506b2eb788f2aeee4ca4d2dcd395
def rate(request, pk):
	exam = float(request.POST.get('exam_box', None))
	quiz = float(request.POST.get('quiz_box', None))
	hw = float(request.POST.get('hw_box', None))
	att = float(request.POST.get('att_box', None))
	lec = float(request.POST.get('lec_box', None))
	comment = request.POST.get('comment_box', None)
	avg = (exam + quiz + hw + att + lec) / 5
	r = Ratings.objects.all()
	num_ratings = r.count()
	num_ratings += 1
	userid = request.user.username
	user = Students.objects.filter(username=userid)
	Ratings(r_id=num_ratings, r_s_id=user[0].s_id, r_l_id=pk, exam_rating=exam, quiz_rating=quiz, hw_rating=hw, \
			att_rating=att, lec_rating=lec, avg_rating=avg, comment=comment).save()

	return detail(request, pk)
<<<<<<< HEAD

=======
>>>>>>> 63093545243e506b2eb788f2aeee4ca4d2dcd395
