from django.urls import path
from . import views

urlpatterns = [
	path('', views.mainpage, name='mainpage'),
	path('lecture_search/', views.search_lecture, name='search_lecture'),
	path('prof_search/', views.search_professor, name="search_professor"),
	path('login/', views.goto_login, name="goto_login"),
	path('signup/', views.goto_signup, name="goto_signup"),
	path('make_login/', views.make_login, name="make_login"),
	path('make_logout/', views.make_logout, name="make_logout"),
	path('make_signup/', views.make_signup, name="make_signup"),
	path('lecture/<str:pk>/', views.detail, name="detail"),
	path('rate/<str:pk>', views.goto_rate, name="goto_rate"),
	path('lecture/rate/<str:pk>', views.rate, name="rate")
]