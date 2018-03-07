# Generated by Django 2.0.1 on 2018-02-01 15:21

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Rating',
            fields=[
                ('r_id', models.AutoField(primary_key=True, serialize=False)),
                ('exam_rating', models.FloatField(verbose_name='시험지수')),
                ('quiz_rating', models.FloatField(verbose_name='퀴즈지수')),
                ('hw_rating', models.FloatField(verbose_name='과제지수')),
                ('att_rating', models.FloatField(verbose_name='출첵지수')),
                ('lec_rating', models.FloatField(verbose_name='강의지수')),
                ('comment', models.CharField(help_text='280 Characters Limited', max_length=280, verbose_name='평가')),
            ],
            options={
                'verbose_name': '리뷰',
                'verbose_name_plural': '리뷰',
            },
        ),
    ]
