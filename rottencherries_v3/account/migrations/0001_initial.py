# Generated by Django 2.0.1 on 2018-02-01 15:21

import account.models
from django.conf import settings
from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    initial = True

    dependencies = [
        migrations.swappable_dependency(settings.AUTH_USER_MODEL),
    ]

    operations = [
        migrations.CreateModel(
            name='Department',
            fields=[
                ('d_id', models.AutoField(primary_key=True, serialize=False)),
                ('d_name', models.CharField(max_length=20, unique=True, verbose_name='학부')),
            ],
            options={
                'verbose_name': '소속대학',
                'verbose_name_plural': '소속대학',
            },
        ),
        migrations.CreateModel(
            name='Major',
            fields=[
                ('m_id', models.AutoField(primary_key=True, serialize=False)),
                ('m_name', models.CharField(max_length=20, unique=True, verbose_name='전공')),
                ('m_d', models.ForeignKey(on_delete=django.db.models.deletion.PROTECT, to='account.Department', verbose_name='소속대학')),
            ],
            options={
                'verbose_name': '전공',
                'verbose_name_plural': '전공',
            },
        ),
        migrations.CreateModel(
            name='Student',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('s_id', models.CharField(max_length=12, unique=True, validators=[account.models.sid_validator], verbose_name='학번')),
                ('s_email', models.EmailField(max_length=254, verbose_name='이메일')),
                ('since_y', models.IntegerField(help_text='e.g. 2018', verbose_name='입학연도')),
                ('s_d', models.ForeignKey(on_delete=django.db.models.deletion.PROTECT, to='account.Department', verbose_name='소속대학')),
                ('s_m', models.ForeignKey(on_delete=django.db.models.deletion.PROTECT, to='account.Major', verbose_name='전공')),
                ('user', models.OneToOneField(on_delete=django.db.models.deletion.CASCADE, to=settings.AUTH_USER_MODEL)),
            ],
            options={
                'verbose_name': '학생',
                'verbose_name_plural': '학생',
            },
        ),
        migrations.AlterUniqueTogether(
            name='major',
            unique_together={('m_id', 'm_d')},
        ),
    ]