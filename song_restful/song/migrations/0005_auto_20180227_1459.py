# Generated by Django 2.0.1 on 2018-02-27 05:59

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('song', '0004_auto_20180226_2126'),
    ]

    operations = [
        migrations.AddField(
            model_name='song',
            name='playtime',
            field=models.CharField(blank=True, max_length=7, null=True),
        ),
        migrations.AlterUniqueTogether(
            name='album',
            unique_together={('artist', 'title', 'release_date')},
        ),
    ]
