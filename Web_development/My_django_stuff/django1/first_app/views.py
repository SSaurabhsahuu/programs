from django.shortcuts import render

# Create your views here.
from django.http import HttpResponse
from first_app.models import AccessRecord,Topic,Webpage #>>>>>>>>>>>>>>>>>>>>
                                                                             #
def index(request):                                                          #
    return HttpResponse("Hello World!")                                      #
                                                                             #
def help(request):                                                           #
    my_dict={'temp':'Do not Hesitate' }                                      #
    return render(request,"first_app/help.html",context=my_dict)             #
                                                                             #
def database(request):                                                       #
        webpages_list=AccessRecord.objects.order_by('date')#<<<<<<<<<<<<<<<<<
        date_dict={'access_records':webpages_list}
        return render(request,'first_app/database.html',context=date_dict)
