void max_heapify(int a[],int n,int i){
	int left=2*i;
	int right=2*i+1;
	int largest;
	if(left<=n && a[left]>a[i]){
		largest=left;
	}else{
		largest=i;
	}
	if(right<=n && a[right]>a[largest]){
		largest=right;
	}
	if(largest!=i){
	int	temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
	max_heapify(a,n,largest);
	}
}
 
void build_heap(int a[],int n){
	for(int i=n/2;i>=0;i--){
        max_heapify(a,n,i);
	}
}
 
int main(){
	int num,num1;
	scanf("%d%d", &num,&num1);
	//printf("%d%d\n",num,num1);              			// Reading input from 
	int a[1000000];
	int sum=0;
	for(int i=0;i<num;++i){
			scanf("%d",&a[i]);
			//printf("%d",a[i]);
	}
	build_heap(a,num);
	while(num1--){
      sum+=a[0];
	  a[0]--;
	  max_heapify(a,num,0);
	  	//for(int i=0;i<num;i++){
			//printf("%d\t",a[i]);
    }
	printf("%d",sum);
 
	
 
	//while(num1--){
	
 
	//}       // Writing output to STDOUT
}