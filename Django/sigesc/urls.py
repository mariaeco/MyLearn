from django.urls import path
from sigesc.views import home


urlpatterns = [
    path('', home),#home
]

