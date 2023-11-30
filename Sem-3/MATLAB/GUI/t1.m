function varargout = t1(varargin)
% T1 MATLAB code for t1.fig
%      T1, by itself, creates a new T1 or raises the existing
%      singleton*.
%
%      H = T1 returns the handle to a new T1 or the handle to
%      the existing singleton*.
%
%      T1('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in T1.M with the given input arguments.
%
%      T1('Property','Value',...) creates a new T1 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before t1_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to t1_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help t1

% Last Modified by GUIDE v2.5 07-Feb-2022 17:36:07

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @t1_OpeningFcn, ...
                   'gui_OutputFcn',  @t1_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before t1 is made visible.
function t1_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to t1 (see VARARGIN)

% Choose default command line output for t1
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes t1 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = t1_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on selection change in sem.
function sem_Callback(hObject, eventdata, handles)
% hObject    handle to sem (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns sem contents as cell array
%        contents{get(hObject,'Value')} returns selected item from sem


% --- Executes during object creation, after setting all properties.
function sem_CreateFcn(hObject, eventdata, handles)
% hObject    handle to sem (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in cs.
function cs_Callback(hObject, eventdata, handles)
% hObject    handle to cs (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cs


% --- Executes on button press in che.
function che_Callback(hObject, eventdata, handles)
% hObject    handle to che (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of che


% --- Executes on button press in maths.
function maths_Callback(hObject, eventdata, handles)
% hObject    handle to maths (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of maths


% --- Executes on button press in phy.
function phy_Callback(hObject, eventdata, handles)
% hObject    handle to phy (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of phy


% --- Executes on button press in submit.
function submit_Callback(hObject, eventdata, handles)
% hObject    handle to submit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if get(handles.male,'Value') == 1
    sex='Gender = Male';
else
    sex = 'Gender = Female';
end
set(handles.sext,'String',sex);

switch get(handles.sem,'Value')
    case 1
        sem = 'Semester NOT Choosen';
    case 2
        sem = 'Sem-I';
    case 3
        sem = 'Sem-II';
    case 4
        sem = 'Sem-III';
    case 5
        sem = 'Sem-IV';
    case 6
        sem = 'Sem-V';
    case 7
        sem = 'Sem-VI';
end
set(handles.semt,'String',sem);

sub = "Subject = ";
n=0;
if get(handles.cs,'Value') == 1
    sub = strcat(sub,"Computer     ");
    n = n+1;
end
if get(handles.phy,'Value') == 1
    sub = strcat(sub,"Physics     ");
    n = n+1;
end
if get(handles.che,'Value') == 1
    sub = strcat(sub,"Chemistry     ");
    n = n+1;
end
if get(handles.maths,'Value') == 1
    sub = strcat(sub,"Mathematics     ");
    n = n+1;
end
if n==0
    sub = "Subjects NOT Choosen";
end
set(handles.subt,'String',sub);